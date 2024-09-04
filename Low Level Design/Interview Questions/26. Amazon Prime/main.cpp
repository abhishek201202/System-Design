/*
Blog - https://lldcoding.com/design-lld-amazon-prime-video-machine-coding
FR - 
1. user can manage their prime membership
2. Upload / watch  Video
3. can watch prime videos
4. offline downloading
5. Live Sports
6. 4k and hdr streaming
*/

/*

VideoCatalog
------------------------


Video
------------------------


Movie (Video)
------------------------


TVShow (Video)
------------------------

VideoFactory
------------------------

MovieFactory (VideoFactory)
------------------------


TVShowFactory (VideoFactory)
------------------------


VideoNotifier
------------------------
vector<User> observer;


User
------------------------


RecommendationStrategy (PopularVideosStrategy, PersonalizedVideosStrategy)
------------------------


VideoCommand
------------------------

AddToWatchlistCommand (VideoCommand)
------------------------

RemoveFromWatchlistCommand (VideoCommand)
------------------------


VideoDecorator
------------------------


SubtitledVideo (VideoDecorator)
------------------------


HDVideo (VideoDecorator)
------------------------



Playlist (Video)
------------------------


BasicPlaylist (playlist)
------------------------


VideoState
------------------------


PlayingState (VideoState)
------------------------


StoppedState (VideoState)
------------------------


StreamingVideo (VideoState)
------------------------


StreamingVideo (Video)
------------------------


VideoProxy (Video)
------------------------


*/


#include<bits/stdc++.h>
using namespace std;

class Video;

// VideoCatalog Singleton
class VideoCatalog {
private:
    static VideoCatalog* instance;
    vector<shared_ptr<Video>> videos;
    
    VideoCatalog() {}
    
public:
    static VideoCatalog* getInstance() {
        if (instance == nullptr) {
            instance = new VideoCatalog();
        }
        return instance;
    }
    
    void addVideo(shared_ptr<Video> video) {
        videos.push_back(video);
    }
    
    shared_ptr<Video> getVideo(const string& videoId) {
        for (const auto& video : videos) {
            if (video->getId() == videoId) {
                return video;
            }
        }
        return nullptr;
    }
};

VideoCatalog* VideoCatalog::instance = nullptr;

// Video interface
class Video {
public:
    virtual ~Video() = default;
    virtual string getId() const = 0;
    virtual void play() = 0;
    virtual void addToWatchlist() = 0;
    virtual void removeFromWatchlist() = 0;
};

// Movie class
class Movie : public Video {
private:
    string title;
    
public:
    Movie(const string& title) : title(title) {}
    
    string getId() const override {
        return title;
    }
    
    void play() override {
        cout << "Playing movie: " << title << endl;
    }
    
    void addToWatchlist() override {
        cout << "Added movie " << title << " to watchlist." << endl;
    }
    
    void removeFromWatchlist() override {
        cout << "Removed movie " << title << " from watchlist." << endl;
    }
};

// TVShow class
class TVShow : public Video {
private:
    string title;
    
public:
    TVShow(const string& title) : title(title) {}
    
    string getId() const override {
        return title;
    }
    
    void play() override {
        cout << "Playing TV show: " << title << endl;
    }
    
    void addToWatchlist() override {
        cout << "Added TV show " << title << " to watchlist." << endl;
    }
    
    void removeFromWatchlist() override {
        cout << "Removed TV show " << title << " from watchlist." << endl;
    }
};

// VideoFactory interface
class VideoFactory {
public:
    virtual ~VideoFactory() = default;
    virtual shared_ptr<Video> createVideo(const string& title) = 0;
};

// MovieFactory class
class MovieFactory : public VideoFactory {
public:
    shared_ptr<Video> createVideo(const string& title) override {
        return make_shared<Movie>(title);
    }
};

// TVShowFactory class
class TVShowFactory : public VideoFactory {
public:
    shared_ptr<Video> createVideo(const string& title) override {
        return make_shared<TVShow>(title);
    }
};

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& message) = 0;
};

// User class
class User : public Observer {
private:
    string userId;
    
public:
    User(const string& userId) : userId(userId) {}
    
    void update(const string& message) override {
        cout << "User " << userId << " received update: " << message << endl;
    }
};

// VideoNotifier class
class VideoNotifier {
private:
    vector<shared_ptr<Observer>> observers;
    
public:
    void addObserver(shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }
    
    void notifyObservers(const string& message) {
        for (const auto& observer : observers) {
            observer->update(message);
        }
    }
};

// RecommendationStrategy interface
class RecommendationStrategy {
public:
    virtual ~RecommendationStrategy() = default;
    virtual vector<shared_ptr<Video>> recommendVideos(shared_ptr<User> user) = 0;
};

// PopularVideosStrategy class
class PopularVideosStrategy : public RecommendationStrategy {
public:
    vector<shared_ptr<Video>> recommendVideos(shared_ptr<User> user) override {
        // Implementation details...
        return {};
    }
};

// PersonalizedVideosStrategy class
class PersonalizedVideosStrategy : public RecommendationStrategy {
public:
    vector<shared_ptr<Video>> recommendVideos(shared_ptr<User> user) override {
        // Implementation details...
        return {};
    }
};

// VideoCommand interface
class VideoCommand {
public:
    virtual ~VideoCommand() = default;
    virtual void execute() = 0;
};

// AddToWatchlistCommand class
class AddToWatchlistCommand : public VideoCommand {
private:
    shared_ptr<Video> video;
    
public:
    AddToWatchlistCommand(shared_ptr<Video> video) : video(video) {}
    
    void execute() override {
        video->addToWatchlist();
    }
};

// RemoveFromWatchlistCommand class
class RemoveFromWatchlistCommand : public VideoCommand {
private:
    shared_ptr<Video> video;
    
public:
    RemoveFromWatchlistCommand(shared_ptr<Video> video) : video(video) {}
    
    void execute() override {
        video->removeFromWatchlist();
    }
};

// VideoDecorator abstract class
class VideoDecorator : public Video {
protected:
    shared_ptr<Video> decoratedVideo;
    
public:
    VideoDecorator(shared_ptr<Video> decoratedVideo) : decoratedVideo(decoratedVideo) {}
    
    string getId() const override {
        return decoratedVideo->getId();
    }
    
    void play() override {
        decoratedVideo->play();
    }
    
    void addToWatchlist() override {
        decoratedVideo->addToWatchlist();
    }
    
    void removeFromWatchlist() override {
        decoratedVideo->removeFromWatchlist();
    }
};

// SubtitledVideo class
class SubtitledVideo : public VideoDecorator {
public:
    SubtitledVideo(shared_ptr<Video> decoratedVideo) : VideoDecorator(decoratedVideo) {}
    
    void play() override {
        cout << "Playing subtitled video..." << endl;
        VideoDecorator::play();
    }
};

// HDVideo class
class HDVideo : public VideoDecorator {
public:
    HDVideo(shared_ptr<Video> decoratedVideo) : VideoDecorator(decoratedVideo) {}
    
    void play() override {
        cout << "Playing HD video..." << endl;
        VideoDecorator::play();
    }
};

// Playlist interface
class Playlist : public Video {
public:
    virtual void addVideo(shared_ptr<Video> video) = 0;
    virtual void removeVideo(shared_ptr<Video> video) = 0;
};

// BasicPlaylist class
class BasicPlaylist : public Playlist {
private:
    vector<shared_ptr<Video>> videos;
    
public:
    void addVideo(shared_ptr<Video> video) override {
        videos.push_back(video);
    }
    
    void removeVideo(shared_ptr<Video> video) override {
        videos.erase(remove(videos.begin(), videos.end(), video), videos.end());
    }
    
    void play() override {
        cout << "Playing all videos in the playlist..." << endl;
        for (const auto& video : videos) {
            video->play();
        }
    }
};

// VideoState interface
class VideoState {
public:
    virtual ~VideoState() = default;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

// PlayingState class
class PlayingState : public VideoState {
public:
    void play() override {
        cout << "Video is already playing." << endl;
    }
    
    void pause() override {
        cout << "Pausing video..." << endl;
    }
    
    void stop() override {
        cout << "Stopping video..." << endl;
    }
};

// PausedState class
class PausedState : public VideoState {
public:
    void play() override {
        cout << "Resuming video..." << endl;
    }
    
    void pause() override {
        cout << "Video is already paused." << endl;
    }
    
    void stop() override {
        cout << "Stopping video..." << endl;
    }
};

// StoppedState class
class StoppedState : public VideoState {
public:
    void play() override {
        cout << "Starting to play video..." << endl;
    }
    
    void pause() override {
        cout << "Cannot pause. Video is stopped." << endl;
    }
    
    void stop() override {
        cout << "Video is already stopped." << endl;
    }
};

// StreamingVideo class
class StreamingVideo : public Video {
private:
    string videoId;
    
public:
    StreamingVideo(const string& videoId) : videoId(videoId) {}
    
    string getId() const override {
        return videoId;
    }
    
    void play() override {
        cout << "Playing streaming video " << videoId << "..." << endl;
    }
    
    void addToWatchlist() override {}
    
    void removeFromWatchlist() override {}
};

// VideoProxy class
class VideoProxy : public Video {
private:
    shared_ptr<Video> video;
    shared_ptr<User> user;
    
public:
    VideoProxy(shared_ptr<Video> video, shared_ptr<User> user)
        : video(video), user(user) {}
    
    string getId() const override {
        return video->getId();
    }
    
    void play() override {
        if (userHasSubscription()) {
            video->play();
        } else {
            cout << "User does not have a subscription." << endl;
        }
    }
    
    void addToWatchlist() override {
        video->addToWatchlist();
    }
    
    void removeFromWatchlist() override {
        video->removeFromWatchlist();
    }
    
private:
    bool userHasSubscription() const {
        // Check user subscription status...
        return true;
    }
};

// Main function
int main() {
    shared_ptr<User> user1 = make_shared<User>("user1");
    shared_ptr<User> user2 = make_shared<User>("user2");

    VideoCatalog* videoCatalog = VideoCatalog::getInstance();

    shared_ptr<Video> movie = make_shared<Movie>("Inception");
    shared_ptr<Video> tvShow = make_shared<TVShow>("Breaking Bad");

    videoCatalog->addVideo(movie);
    videoCatalog->addVideo(tvShow);

    VideoNotifier videoNotifier;
    videoNotifier.addObserver(user1);
    videoNotifier.addObserver(user2);

    videoNotifier.notifyObservers("New video available!");

    shared_ptr<RecommendationStrategy> strategy = make_shared<PopularVideosStrategy>();
    vector<shared_ptr<Video>> recommendations = strategy->recommendVideos(user1);
    cout << "Recommendations for user1: " << recommendations.size() << endl;

    shared_ptr<VideoCommand> addToWatchlistCommand = make_shared<AddToWatchlistCommand>(movie);
    addToWatchlistCommand->execute();

    shared_ptr<VideoCommand> removeFromWatchlistCommand = make_shared<RemoveFromWatchlistCommand>(tvShow);
    removeFromWatchlistCommand->execute();

    shared_ptr<VideoDecorator> subtitledMovie = make_shared<SubtitledVideo>(movie);
    subtitledMovie->play();

    shared_ptr<VideoDecorator> hdTvShow = make_shared<HDVideo>(tvShow);
    hdTvShow->play();

    shared_ptr<Playlist> playlist = make_shared<BasicPlaylist>();
    playlist->addVideo(movie);
    playlist->addVideo(tvShow);
    playlist->play();

    shared_ptr<VideoState> playingState = make_shared<PlayingState>();
    playingState->play();
    playingState->pause();
    playingState->stop();

    shared_ptr<Video> video = make_shared<StreamingVideo>("xyz123");
    shared_ptr<VideoProxy> videoProxy = make_shared<VideoProxy>(video, user1);
    videoProxy->play();

    return 0;
}

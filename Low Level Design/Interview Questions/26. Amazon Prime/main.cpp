/*
FR - 
1. user can manage their prime membership
2. Upload / watch  Video
3. can watch prime videos
4. offline downloading
5. Live Sports
6. 4k and hdr streaming

*/


#include<bits/stdc++.h>
using namespace std;

// Enum for Subscription Status
enum class SubscriptionStatus {
    Subscribed,
    NotSubscribed
};

// User Class
class User {
public:
    string userID;
    string name;
    string email;
    SubscriptionStatus subscriptionStatus;
    vector<string> offlineDownloads;
    User(const string& id, const string& nm, const string& em, SubscriptionStatus status) : userID(id), name(nm), email(em), subscriptionStatus(status) {}
    void subscribeToPrime() {
        subscriptionStatus = SubscriptionStatus::Subscribed;
        cout << name << " has subscribed to Amazon Prime Video.\n";
    }
    void cancelPrimeSubscription() {
        subscriptionStatus = SubscriptionStatus::NotSubscribed;
        cout << name << " has canceled their Amazon Prime Video subscription.\n";
    }
    void downloadVideo(const string& videoID) {
        offlineDownloads.push_back(videoID);
        cout << "Video " << videoID << " has been downloaded for offline viewing.\n";
    }
    void manageOfflineDownloads() {
        cout << "Offline downloads for " << name << ": ";
        for (const auto& video : offlineDownloads) {
            cout << video << " ";
        }
        cout << endl;
    }
};

// Video Class
class Video {
public:
    string videoID;
    string title;
    string genre;
    int duration; // Duration in seconds
    string quality; // e.g., "HD", "4K", "HDR"
    Video(const string& id, const string& ttl, const string& gnr, int dur, const string& qlt) : videoID(id), title(ttl), genre(gnr), duration(dur), quality(qlt) {}
    void getDetails() const {
        cout << "Title: " << title << ", Genre: " << genre << ", Duration: " << duration << "s, Quality: " << quality << endl;
    }
};

// VideoCatalog Class
class VideoCatalog {
private:
    unordered_map<string, Video> catalog;
public:
    void addVideo(const Video& video) {
        catalog[video.videoID] = video;
    }
    Video* findVideo(const string& title) {
        for (auto& pair : catalog) {
            if (pair.second.title == title) {
                return &pair.second;
            }
        }
        return nullptr;
    }
};

// StreamingService Class
class StreamingService {
private:
    const Video* currentVideo;
    int currentPosition; // Position in seconds
    string streamingQuality; // e.g., "HD", "4K", "HDR"
public:
    StreamingService() : currentVideo(nullptr), currentPosition(0), streamingQuality("HD") {}
    void playVideo(const Video& video) {
        currentVideo = &video;
        currentPosition = 0;
        cout << "Playing video: " << video.title << endl;
    }
    void pause() {
        cout << "Pausing video at " << currentPosition << " seconds.\n";
    }
    void resume() {
        cout << "Resuming video from " << currentPosition << " seconds.\n";
    }
    void stop() {
        cout << "Stopping video.\n";
        currentVideo = nullptr;
        currentPosition = 0;
    }
    void buffering() {
        cout << "Buffering...\n";
    }
    void setStreamingQuality(const string& quality) {
        streamingQuality = quality;
        cout << "Streaming quality set to " << quality << endl;
    }
};

// OfflineDownloader Class
class OfflineDownloader {
private:
    unordered_map<string, Video> downloadedVideos;
public:
    void downloadVideo(const Video& video) {
        downloadedVideos[video.videoID] = video;
        cout << "Video " << video.title << " has been downloaded for offline viewing.\n";
    }
    void getDownloadedVideos() const {
        cout << "Downloaded videos: ";
        for (const auto& pair : downloadedVideos) {
            cout << pair.second.title << " ";
        }
        cout << endl;
    }
};

// LiveSportsService Class
class LiveSportsService {
private:
    unordered_map<string, bool> liveEvents; // Event ID and its status
public:
    void startLiveEvent(const string& eventID) {
        liveEvents[eventID] = true;
        cout << "Live sports event " << eventID << " started.\n";
    }

    void stopLiveEvent(const string& eventID) {
        liveEvents[eventID] = false;
        cout << "Live sports event " << eventID << " stopped.\n";
    }
};

// SubscriptionManager Class
class SubscriptionManager {
public:
    bool checkSubscriptionStatus(const User& user) {
        return user.subscriptionStatus == SubscriptionStatus::Subscribed;
    }
    void updateSubscriptionStatus(User& user, bool status) {
        user.subscriptionStatus = status ? SubscriptionStatus::Subscribed : SubscriptionStatus::NotSubscribed;
        cout << (status ? "User is now subscribed to Prime Video." : "User subscription to Prime Video has been canceled.") << endl;
    }
};

// PrimeVideoService Class
class PrimeVideoService {
private:
    User& user;
    VideoCatalog videoCatalog;
    StreamingService streamingService;
    OfflineDownloader offlineDownloader;
    LiveSportsService liveSportsService;
    SubscriptionManager subscriptionManager;
public:
    PrimeVideoService(User& u) : user(u), subscriptionManager() {}
    void addVideoToCatalog(const Video& video) {
        videoCatalog.addVideo(video);
    }
    void playVideo(const string& title) {
        if (subscriptionManager.checkSubscriptionStatus(user)) {
            Video* video = videoCatalog.findVideo(title);
            if (video) {
                streamingService.playVideo(*video);
            } else {
                cout << "Video not found in catalog.\n";
            }
        } else {
            cout << "User is not subscribed to Prime Video.\n";
        }
    }
    void pauseVideo() {
        streamingService.pause();
    }
    void resumeVideo() {
        streamingService.resume();
    }
    void stopVideo() {
        streamingService.stop();
    }
    void bufferVideo() {
        streamingService.buffering();
    }
    void setStreamingQuality(const string& quality) {
        streamingService.setStreamingQuality(quality);
    }
    void downloadVideo(const Video& video) {
        offlineDownloader.downloadVideo(video);
        user.downloadVideo(video.videoID);
    }
    void manageOfflineDownloads() {
        user.manageOfflineDownloads();
    }
    void startLiveEvent(const string& eventID) {
        liveSportsService.startLiveEvent(eventID);
    }
    void stopLiveEvent(const string& eventID) {
        liveSportsService.stopLiveEvent(eventID);
    }
    void getDownloadedVideos() {
        offlineDownloader.getDownloadedVideos();
    }
};

// Main function to simulate the system
int main() {
    // Create a user
    User user("user001", "Alice", "alice@example.com", SubscriptionStatus::Subscribed);

    // Create a PrimeVideoService for the user
    PrimeVideoService primeVideoService(user);

    // Add videos to catalog
    Video video1("vid001", "Movie A", "Action", 120, "4K");
    Video video2("vid002", "Movie B", "Drama", 90, "HDR");

    primeVideoService.addVideoToCatalog(video1);
    primeVideoService.addVideoToCatalog(video2);

    // Play a video
    primeVideoService.playVideo("Movie A");

    // Set streaming quality
    primeVideoService.setStreamingQuality("4K");

    // Download a video
    primeVideoService.downloadVideo(video1);

    // Manage offline downloads
    primeVideoService.manageOfflineDownloads();

    // Start a live sports event
    primeVideoService.startLiveEvent("event001");

    // Stop a live sports event
    primeVideoService.stopLiveEvent("event001");

    // Get downloaded videos
    primeVideoService.getDownloadedVideos();

    // Pause, resume, and stop video playback
    primeVideoService.pauseVideo();
    primeVideoService.resumeVideo();
    primeVideoService.stopVideo();

    return 0;
}

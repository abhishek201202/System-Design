/*
This pattern helps to hide the system complexity from the client.
*/
#include<bits/stdc++.h>
using namespace std;

// Subsystem 1: DVD Player
class DVDPlayer {
public:
    void on() {
        cout << "DVD Player is ON.\n";
    }
    void play(string movie) {
        cout << "Playing movie: " << movie << endl;
    }
    void stop() {
        cout << "Stopping movie.\n";
    }
    void off() {
        cout << "DVD Player is OFF.\n";
    }
};

// Subsystem 2: Amplifier
class Amplifier {
public:
    void on() {
        cout << "Amplifier is ON.\n";
    }
    void setVolume(int level) {
        cout << "Setting volume to " << level << endl;
    }
    void off() {
        cout << "Amplifier is OFF.\n";
    }
};

// Subsystem 3: Projector
class Projector {
public:
    void on() {
        cout << "Projector is ON.\n";
    }
    void wideScreenMode() {
        cout << "Projector in widescreen mode.\n";
    }
    void off() {
        cout << "Projector is OFF.\n";
    }
};

// Subsystem 4: Theater Lights
class TheaterLights {
public:
    void dim(int level) {
        cout << "Dimming lights to " << level << "%\n";
    }
    void on() {
        cout << "Theater lights are ON.\n";
    }
};

// Facade: Provides a simplified interface to the complex subsystem
class HomeTheaterFacade {
private:
    DVDPlayer& dvdPlayer;
    Amplifier& amplifier;
    Projector& projector;
    TheaterLights& lights;
public:
    HomeTheaterFacade(DVDPlayer& dvd, Amplifier& amp, Projector& proj, TheaterLights& light) : dvdPlayer(dvd), amplifier(amp), projector(proj), lights(light) {}
    void watchMovie(const string& movie) {
        cout << "Get ready to watch a movie...\n";
        lights.dim(10);
        projector.on();
        projector.wideScreenMode();
        amplifier.on();
        amplifier.setVolume(5);
        dvdPlayer.on();
        dvdPlayer.play(movie);
    }
    void endMovie() {
        cout << "Shutting movie theater down...\n";
        dvdPlayer.stop();
        dvdPlayer.off();
        amplifier.off();
        projector.off();
        lights.on();
    }
};

// Usage
int main() {
    DVDPlayer dvdPlayer;
    Amplifier amplifier;
    Projector projector;
    TheaterLights lights;

    HomeTheaterFacade homeTheater(dvdPlayer, amplifier, projector, lights);

    homeTheater.watchMovie("Inception");
    cout << endl;
    homeTheater.endMovie();

    return 0;
}

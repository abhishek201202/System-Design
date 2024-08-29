/*
This pattern helps to hide the system complexity from the client.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Subsystem 1: DVD Player
class DVDPlayer {
public:
    void on() {
        std::cout << "DVD Player is ON.\n";
    }
    void play(std::string movie) {
        std::cout << "Playing movie: " << movie << "\n";
    }
    void stop() {
        std::cout << "Stopping movie.\n";
    }
    void off() {
        std::cout << "DVD Player is OFF.\n";
    }
};

// Subsystem 2: Amplifier
class Amplifier {
public:
    void on() {
        std::cout << "Amplifier is ON.\n";
    }
    void setVolume(int level) {
        std::cout << "Setting volume to " << level << "\n";
    }
    void off() {
        std::cout << "Amplifier is OFF.\n";
    }
};

// Subsystem 3: Projector
class Projector {
public:
    void on() {
        std::cout << "Projector is ON.\n";
    }
    void wideScreenMode() {
        std::cout << "Projector in widescreen mode.\n";
    }
    void off() {
        std::cout << "Projector is OFF.\n";
    }
};

// Subsystem 4: Theater Lights
class TheaterLights {
public:
    void dim(int level) {
        std::cout << "Dimming lights to " << level << "%\n";
    }
    void on() {
        std::cout << "Theater lights are ON.\n";
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
    HomeTheaterFacade(DVDPlayer& dvd, Amplifier& amp, Projector& proj, TheaterLights& light)
        : dvdPlayer(dvd), amplifier(amp), projector(proj), lights(light) {}

    void watchMovie(const std::string& movie) {
        std::cout << "Get ready to watch a movie...\n";
        lights.dim(10);
        projector.on();
        projector.wideScreenMode();
        amplifier.on();
        amplifier.setVolume(5);
        dvdPlayer.on();
        dvdPlayer.play(movie);
    }

    void endMovie() {
        std::cout << "Shutting movie theater down...\n";
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
    std::cout << "\n";
    homeTheater.endMovie();

    return 0;
}

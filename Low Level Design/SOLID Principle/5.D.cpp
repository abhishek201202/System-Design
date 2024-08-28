/*
class should depend on interfaces rather than concrete classes
*/
#include<bits/stdc++.h>
using namespace std;

// Keyboard(wired, bluetooth)
// Mouse(wired, bluetooth)

// Not following dependency inversion principle
class MacBook {
    WiredKeyboard keyboard;
    WiredMouse mouse;
    public MacBook() {
        keyboard = new WiredKeyboard();
        mouse = new WiredMouse();
    }
};

// Following dependency inversion principle
class MacBook {
    Keyboard keyboard;
    Mouse mouse;
    MackBook(Keyboard keyboard, Mouse mouse) {
        this.keyboard = keyboard;
        this.mouse = mouse;
    }
};

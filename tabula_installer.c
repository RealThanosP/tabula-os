#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

// Define the number of apps available
#define NUM_APPS 5

// Struct to hold app details
typedef struct {
    char *name;
    char *package_cmd;
    int selected;
} App;

int main() {
    // 1. Initialize our list of student apps
    App apps[NUM_APPS] = {
        {"Visual Studio Code", "code", 0},
        {"LibreOffice", "libreoffice-fresh", 0},
        {"Obsidian (Notes)", "obsidian", 0},
        {"Spotify", "spotify-launcher", 0},
        {"GIMP (Image Editor)", "gimp", 0}
    };

    // 2. Start ncurses mode
    initscr();
    cbreak();             // Disable line buffering (pass input immediately)
    noecho();             // Don't print user input (keys) to screen
    keypad(stdscr, TRUE); // Enable special keys (arrows, F-keys)
    curs_set(0);          // Hide the blinking cursor

    int highlight = 0;
    int choice;
    int ch;

    // 3. The Main Loop (Navigation)
    while(1) {
        clear(); // Clear screen for redraw

        // Draw the Title
        attron(A_BOLD);
        mvprintw(1, 2, "Welcome to TabulaOS Setup");
        mvprintw(2, 2, "Use UP/DOWN to move, SPACE to select, ENTER to install.");
        attroff(A_BOLD);

        // Draw the Menu
        for(int i = 0; i < NUM_APPS; i++) {
            // Determine if this row is highlighted
            if(i == highlight) {
                attron(A_REVERSE); // Invert colors for the cursor
            }

            // Draw the Checkbox [ ] or [x]
            mvprintw(4 + i, 4, "[%c] %s", apps[i].selected ? 'x' : ' ', apps[i].name);

            // Turn off highlight
            if(i == highlight) {
                attroff(A_REVERSE);
            }
        }

        // 4. Handle Input
        ch = getch();
        switch(ch) {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight >= NUM_APPS) highlight = NUM_APPS - 1;
                break;
            case ' ': // Spacebar toggles selection
                apps[highlight].selected = !apps[highlight].selected;
                break;
            case 10: // Enter key (ASCII 10) breaks the loop to start install
                goto install_phase;
                break;
        }
    }

    install_phase:
    // 5. The "Installation" Logic
    endwin(); // Close ncurses window and go back to normal terminal
    
    printf("TabulaOS is now configuring your system...\n");
    printf("-----------------------------------------\n");
    
    // Construct the pacman command
    // In a real scenario, you would concatenate the string and run system()
    for(int i = 0; i < NUM_APPS; i++) {
        if(apps[i].selected) {
            printf("Installing: %s...\n", apps[i].name);
            // Example of how you would run the real command:
            // char cmd[100];
            // sprintf(cmd, "pacman -S %s --noconfirm", apps[i].package_cmd);
            // system(cmd);
        }
    }
    
    printf("-----------------------------------------\n");
    printf("Setup Complete! Welcome to TabulaOS.\n");

    return 0;
}
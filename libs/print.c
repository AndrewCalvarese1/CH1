#include <libetc.h>
#include <string.h>

#define MAX_MESSAGES 10
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char text[MAX_MESSAGE_LENGTH];
    int timer;
    int active;
} Message;

static Message messages[MAX_MESSAGES];

void initPrint() {
    int i;
    for (i = 0; i < MAX_MESSAGES; i++) {
        messages[i].active = 0;
        messages[i].timer = 0;
        strcpy(messages[i].text, "");
    }
}

void printMessage(char* text, int duration) {
    int i;
    // Find first available slot
    for (i = 0; i < MAX_MESSAGES; i++) {
        if (!messages[i].active) {
            strcpy(messages[i].text, text);
            messages[i].timer = duration;
            messages[i].active = 1;
            break;
        }
    }
}

void printMessageForever(char* text) {
    printMessage(text, -1); // -1 means forever
}

void updatePrint() {
    int i;
    for (i = 0; i < MAX_MESSAGES; i++) {
        if (messages[i].active) {
            FntPrint("%s\n", messages[i].text);
            
            if (messages[i].timer > 0) {
                messages[i].timer--;
                if (messages[i].timer == 0) {
                    messages[i].active = 0;
                }
            }
            // If timer is -1, message stays forever
        }
    }
}

void clearAllMessages() {
    int i;
    for (i = 0; i < MAX_MESSAGES; i++) {
        messages[i].active = 0;
    }
}
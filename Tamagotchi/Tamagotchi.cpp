#include "Tamagotchi.h"

namespace Tamagotchi {
    void Tamagotchi::AddCommand_Immediate(Command c) {
        //add to start of queue
        this->Commands.push_front(c);
    }

    IStatus& Tamagotchi::getStatus() {
        return this->Stats;
    }

    Command Tamagotchi::GetCurrentCommand() {
        if (this->Commands.empty()) {
            return idle;
        }
        else {
            return this->Commands.front();
        }
    }
}
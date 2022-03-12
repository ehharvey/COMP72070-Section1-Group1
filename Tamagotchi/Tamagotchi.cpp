#include "Tamagotchi.h"

namespace Tamagotchi {
    void Tamagotchi::AddCommand(Command)
    {
    }
    void Tamagotchi::AddCommand_Immediate(Command c) {
        //add to start of queue
        this->Commands.push_front(c);
    }

    IStatus& Tamagotchi::getStatus() {
        return this->Stats;
    }

    void Tamagotchi::adjustStat(Stat, signed int relativeChange)
    {
    }

    Command Tamagotchi::GetCurrentCommand() {
        if (this->Commands.empty()) {
            return idle;
        }
        else {
            return this->Commands.front();
        }
    }
    void Status::setHappiness(uint8_t happiness)
    {
    }

    void Status::setAlertness(uint8_t alertness)
    {
    }

    void Status::setStomachLevel(uint8_t stomach)
    {
    }

    void Status::setCleaniness(uint8_t cleaniness)
    {
    }

    void Status::setStats(uint8_t Happiness, uint8_t Alertness, uint8_t Cleanliness, uint8_t StomachLevel)
    {
    }

}
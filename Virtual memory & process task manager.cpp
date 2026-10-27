#include <iostream>
#include <string>
enum ProcessState{
    READY,
    RUNNING,
    TERMINATED,
};
struct MemoryBlock{
    int startAddress;
    int size;
    bool isAllocated = false;
    int processID = -1;
};
void printBlockInfo(const MemoryBlock &Info ){
    std::cout << (Info.isAllocated ? "YES" : "NO") << "\n";
    std::cout << Info.processID << "\n";
    std::cout << Info.size << "\n";
    std::cout << Info.startAddress << "\n";
}

class Process{
    protected:
        int id;
        std::string name;
        int requiredMemory;
        ProcessState state = READY;
    public:
        Process(int id,std::string name,int requiredMemory){
            this->id = id;
            this->name = name;
            this->requiredMemory = requiredMemory;
        }
        int getID(){
            return this -> id;
        }
        std::string getName(){
            return this -> name;
        }
        int getRequiredMemory(){
            return this->requiredMemory;
        }
        ProcessState getState(){
            return this -> state;
        }
        void setState(ProcessState newState){
            this -> state = newState;
        }
        virtual void displayInfo(){
        std::cout << getID() << "\n";
        std::cout << getName()<< "\n";
        std::cout << getRequiredMemory() << "\n";
        std::cout << getState() << "\n";
        }
};
class UserProcess : public Process {
    public: 
        UserProcess(int id,std::string name,int requiredMemory) : Process(id,name,requiredMemory){

        }
        void displayInfo(){
        std::cout << "USER PROCESS" << "\n";
        std::cout << getID() << "\n";
        std::cout << getName()<< "\n";
        std::cout << getRequiredMemory() << "\n";
        std::cout << getState() << "\n";
        }

};
class SystemProcess : public Process {
    private:
    bool isCritical = true;
    public: 
        SystemProcess(int id,std::string name,int requiredMemory) : Process(id,name,requiredMemory){
        }
        void displayInfo(){
        std::cout << "SYSTEM PROCESS" << "\n";
        std::cout << getID() << "\n";
        std::cout << getName()<< "\n";
        std::cout << getRequiredMemory() << "\n";
        std::cout << getState() << "\n";
        }

};
class MemoryManager{
    private:
        int TotalCapacity;
        int blockCount;
        MemoryBlock *blocks = nullptr;
    public:
        MemoryManager(int capacity = 128){
            TotalCapacity = capacity;  
            blocks = new MemoryBlock[capacity];
            blocks[0].startAddress = 0;
            blocks[0].size = capacity;
            blocks[0].isAllocated = false;
            blocks[0].processID = -1;
            blockCount = 1;
        }
        bool Allocate(Process &p){
            for(int i = 0; i < blockCount; i++ ){
                if (blocks[i].isAllocated==false && blocks[i].size >= p.getRequiredMemory()){
                    blocks[i].isAllocated = true;
                    blocks[i].processID = p.getID();
                    return true;
                }
            }
            std::cout << "Error not enough RAM"<<"\n";
            return false;
        }
        void Deallocate(int processid){
            for(int i = 0; i < blockCount; i++ ){
                if(blocks[i].processID == processid){
                    blocks[i].isAllocated = false;
                    blocks[i].processID =-1;
                    std::cout << "ID deallocated"<<"\n";
                }
            }
        }

        ~MemoryManager() {
            delete[] blocks;    
        }

};

int main(){
    MemoryManager ram(128);

    UserProcess user1(100,"Spotify",20);
    user1.displayInfo();
    SystemProcess system1(200,"Chrome",10);
    system1.displayInfo();

    ram.Allocate(user1);
    ram.Allocate(system1);
    ram.Deallocate(100);

    return 0;
}
#ifndef _PROC_MANAGER_H
#define _PROC_MANAGER_H
#include <vector>
#include "../include/process.hpp"

class ProcessManager {
        std::vector<ProcessTable*> pidVector;
    public:
        ProcessTable* registerProcess(ProcessStates *process, void *args, TaskPriority prior);
        void unregisterProcess(ProcessTable *process);       
};

extern ProcessManager globalProcessManager;

#endif
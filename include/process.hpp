#ifndef PROC_H
#define PROC_H
#include <string>
#include "task.hpp"

struct ProcessStates {
    JobStatus (*start_proc)(void* );
    JobStatus (*pause_proc)(void* );
    void (*end_proc)(void* );
    void (*fail_proc)(void* );
};

struct TaskData {
    struct ProcessStates *proc;
    void *args;
    TaskPriority priority;
    std::uint16_t starveCounter;
    TaskData(){
        proc = NULL;
        args = NULL;
    };
};

struct TableMetadata {
    std::uint64_t rows;
    std::uint64_t columns;
    std::uint64_t currentRow;
    std::uint64_t currentColumn;
};

struct TableData {
    struct TableMetadata *metadata;
    void* args;
    std::string tableID;
    unsigned int dataLen;
    TaskPriority priority;
    std::string instanceType;

    TableData(std::uint64_t row, std::uint64_t col){
        metadata = new TableMetadata;
        metadata->columns = col;
        metadata->rows = row;
        metadata->currentColumn = 0;
        metadata->currentRow = 0;
    }

    ~TableData(){
        delete metadata;
    }
};

int scheduleTask(struct ThreadPool *thread, struct ProcessStates* proc, 
                void *args, TaskPriority priority);

#endif
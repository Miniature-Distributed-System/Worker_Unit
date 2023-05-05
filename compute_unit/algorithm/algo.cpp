#include <stdlib.h>
#include "algo.hpp"
#include "instance.hpp"
#include "../data_processor.hpp"
#include "../include/process.hpp"
#include "../include/debug_rp.hpp"

InstanceList globalInstanceList;

int sched_algo(struct thread_pool *thread, struct table *tData)
{
    struct process* proc;
    short algoIndex;

    if(!tData){
        DEBUG_ERR(__func__, "table data is uninitlised!");
        return EXIT_FAILURE;
    }

    algoIndex = globalInstanceList.getInstanceFromId(tData->instanceType).getLinkedAlgorithm();
    proc = avial_algo[algoIndex](tData);
    scheduleTask(thread, proc, tData, tData->priority);

    DEBUG_MSG(__func__, "rows:", tData->metadata->rows, " Cols:",tData->metadata->cols);
    DEBUG_MSG(__func__, "Sched algorihm type:",algoIndex);

    return EXIT_SUCCESS;
}

void dealloc_table_dat(struct table *tData)
{
    std::string dropTable = "DROP TABLE " + tData->tableID + ";";
    //Don't care if it fails
    if(dataBaseAccess){
        dataBaseAccess->writeValue(dropTable.c_str());
    }
    delete tData;
}
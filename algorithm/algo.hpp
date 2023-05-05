#ifndef ALGO_H
#define ALGO_H
#include <sqlite3.h>
#include "../sql_access.hpp"
#include "../include/process.hpp"
#include "cand_elim.hpp"
#include "example.hpp"

//bound to change once build root is made
#define TOT_ALGO 2

int sched_algo(struct thread_pool*, struct TableData*);
void dealloc_table_dat(struct TableData *tData);

//add function prototypes below this
struct ProcessStates* init_example_algo(struct TableData*);
struct ProcessStates* init_ce_algorithm(struct TableData*);

static struct ProcessStates* (*avial_algo[TOT_ALGO])(struct TableData*) = {
    init_example_algo,
    init_ce_algorithm
};

typedef Base* BaseMaker();

template <class X> Base* make() {
  return new X;
}

static BaseMaker* makers[TOT_ALGO] = { 
    make<example>, 
    make<candidateElimination> 
};
#endif
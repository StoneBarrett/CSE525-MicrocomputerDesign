#include "entry.h"
#include "mm.h"
#include "printf.h"
#include "sched.h"

int copy_process(unsigned long fn, unsigned long arg, unsigned int prior) {
  preempt_disable();
  struct task_struct *p;

  p = (struct task_struct *)get_free_page();
  if (!p)
    return 1;
  p->priority = prior;
  p->state = TASK_RUNNING;
  p->counter = prior;
  p->preempt_count = 1;

  p->cpu_context.x19 = fn;
  p->cpu_context.x20 = arg;
  p->cpu_context.pc = (unsigned long)ret_from_fork;
  p->cpu_context.sp = (unsigned long)p + THREAD_SIZE;
  int pid = nr_tasks++;
  task[pid] = p;

  printf("\n\rTask #%d created\r\n", pid);
  printf("\n\rallocation address%08x.\r\n", p);
  printf("pc  %08x. (ret_from_fork)\r\n", p->cpu_context.pc);
  printf("sp  %08x. (sp)\r\n", p->cpu_context.sp);

  preempt_enable();
  return 0;
}

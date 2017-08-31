#include "worker.h"
#include <smtp.h>

worker::worker()
{
}
worker::~worker(){
}

void worker::process() {

    // allocate resources using new here

    m_smtp->show();
    emit finished();
}

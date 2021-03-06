/* vim: set et fenc=utf-8 ff=unix ts=4 sw=4 sts=4 : */

#ifndef mqttcd_logger_h
#define mqttcd_logger_h

#include <stdio.h>
#include <stdarg.h>

#ifdef ENABLE_SYSLOG
#include <syslog.h>
#endif

#include "mqttcd_type.h"
#include "mqttcd_process.h"

int logger_open(mqttcd_context_t* context);
void logger_close(mqttcd_context_t* context);

void logger_error(mqttcd_context_t* context, const char* format, ...);
void logger_notice(mqttcd_context_t* context, const char* format, ...);
void logger_debug(mqttcd_context_t* context, const char* format, ...);

#endif


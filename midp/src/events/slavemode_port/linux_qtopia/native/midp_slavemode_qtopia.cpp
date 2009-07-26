/*
 *
 *
 * Copyright  1990-2008 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 *
 * This source file is specific for Qt-based configurations.
 */

#include <midp_slavemode_port.h>
#include <japplication.h>

#include <QtDebug>
/**
 * Requests that the VM control code schedule a time slice as soon
 * as possible, since Java threads are waiting to be run.
 */
extern "C"
void midp_slavemode_schedule_vm_timeslice(void)
{
  // FIXME: What thread are we in? Do we have race conditions here?
  JApplication::instance()->scheduleTimeSlice(0);
}

extern "C"
void midp_slavemode_event_loop(void)
{
  qDebug("slavemode event loop qtopia");
  JApplication::instance()->startVM();
  JApplication::instance()->exec();
  JApplication::instance()->stopVM();
}


extern "C"
void midp_network_status_event_port(int isInit, int status)
{
  (void)isInit;
  (void)status;
}

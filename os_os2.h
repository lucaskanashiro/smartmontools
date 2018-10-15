/*
 * os_os2.c
 *
 * Home page of code is: http://www.smartmontools.org
 *
 * Copyright (C) 2004-8 Yuri Dario
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * You should have received a copy of the GNU General Public License
 * (for example COPYING); if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef OS_OS2_H_
#define OS_OS2_H_

#define OS_XXXX_H_CVSID "$Id: os_os2.h 4431 2017-08-08 19:38:15Z chrfranke $\n"

// Additional material should start here.  Note: to keep the '-V' CVS
// reporting option working as intended, you should only #include
// system include files <something.h>.  Local #include files
// <"something.h"> should be #included in os_generic.c

#define INCL_DOS
#include <os2.h>

#include "os_linux.h"

#pragma pack(1)

/* IOCTL definitions from s506oem.h (primarily required for SMART calls) */
#define DSKSP_CAT_SMART             0x80  /* SMART IOCTL category */
#define DSKSP_SMART_ONOFF           0x20  /* turn SMART on or off */
#define DSKSP_SMART_AUTOSAVE_ONOFF  0x21  /* turn SMART autosave on or off */
#define DSKSP_SMART_SAVE            0x22  /* force save of SMART data */
#define DSKSP_SMART_GETSTATUS       0x23  /* get SMART status (pass/fail) */
#define DSKSP_SMART_GET_ATTRIBUTES  0x24  /* get SMART attributes table */
#define DSKSP_SMART_GET_THRESHOLDS  0x25  /* get SMART thresholds table */
#define DSKSP_SMART_GET_LOG         0x26  /* get SMART log        table */
#define DSKSP_SMART_AUTO_OFFLINE    0x27  /* set SMART offline autosave timer */
#define DSKSP_SMART_EXEC_OFFLINE 0x28 /* execute SMART immediate offline */

#define SMART_CMD_ON      1   /* on  value for related SMART functions */
#define SMART_CMD_OFF     0   /* off value for related SMART functions */

#define DSKSP_CAT_GENERIC           0x90  /* generic IOCTL category */
#define DSKSP_GET_INQUIRY_DATA      0x42  /* get ATA/ATAPI inquiry data */

typedef struct _DSKSP_CommandParameters {
  BYTE byPhysicalUnit;		   /* physical unit number 0-n */
				   /* 0 = 1st disk, 1 = 2nd disk, ...*/
				   /* 0x80 = Pri/Mas, 0x81=Pri/Sla, 0x82=Sec/Mas,*/
} DSKSP_CommandParameters, *PDSKSP_CommandParameters;

struct SMART_ParamExt {
  UCHAR      byPhysicalUnit;  // 0=Pri/Mas, 1=Pri/Sla, 2=Sec/Mas, etc.
  ULONG      LogAddress;      // valid values 0-255. See ATA/ATPI standard
                              // for details
  ULONG      SectorCount;     // valid values 0-255  See ATA/ATPI standard
                              // for details
  ULONG      reserved;        // reserved. must be set to 0
};

const char * danisdev="\\DEV\\IBMS506$"; // DANIS506
const char * danispref="hd";
const char * ahcidev="\\DEV\\OS2AHCI$";  // OS2AHCI
const char * ahcipref="ahci";

#endif /* OS_GENERIC_H_ */

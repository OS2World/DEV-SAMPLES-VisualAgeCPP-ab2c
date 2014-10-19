#ifndef _IVBAB2C_
  #define _IVBAB2C_

/*******************************************************************************
* FILE NAME: ivbvab2c.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*    IVBAboutToCloseHandler         - Handles SC_CLOSE                         *
*    IVBCloseMessageHandler         - Handles WM_CLOSE                         *
*                                                                              *
* COPYRIGHT:                                                                   *
*   IBM(R) VisualAge(TM) C++ for OS/2(R), Version 3                            *
*   (C) Copyright IBM Corporation 1991, 1995.                                  *
*    - Licensed Material - Program-Property of IBM - All Rights Reserved.      *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
*   This program will not run in DOS mode.                                     *
*                                                                              *
*******************************************************************************/

#ifndef _IHANDLER_
   #include <ihandler.hpp>
#endif

#ifndef _ICMDHDR_
  #include <icmdhdr.hpp>
#endif

#ifndef _IMSGBOX_
  #include <imsgbox.hpp>
#endif

#define INCL_WINFRAMEMGR
#include <os2.h>

/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//**************************************************************************
// Class:   IVBAboutToCloseHandler                                         *
//                                                                         *
// Purpose: Handles the SC_CLOSE event.                                    *
//                                                                         *
//**************************************************************************

class IVBAboutToCloseHandler : public ICommandHandler {
public:
  IVBAboutToCloseHandler () {};
protected:
virtual Boolean

  systemCommand ( ICommandEvent& event )
  {
    if (event.commandId() == SC_CLOSE) {
      IMessageBox msgbox (event.controlWindow());

      IMessageBox::Response result = msgbox.show ("Do you want to close?",
          (IMessageBox::okCancelButton |
           IMessageBox::defButton1 |
           IMessageBox::applicationModal)
        );
      if (result == IMessageBox::ok) {
        return false;
      }
      return true;
    }
    return false;
  }
};

//**************************************************************************
// Class:   IVBCloseMessageHandler                                         *
//                                                                         *
// Purpose: Handles the WM_CLOSE event.                                    *
//                                                                         *
//**************************************************************************

class IVBCloseMessageHandler : public IHandler
{
typedef IHandler
   Inherited;
public:
  IVBCloseMessageHandler() {};
virtual ~IVBCloseMessageHandler() {};
protected:
  Boolean dispatchHandlerEvent( IEvent& event )
  {
    if (event.eventId() == WM_CLOSE) {
      IMessageBox msgbox (event.controlWindow());

      IMessageBox::Response result = msgbox.show ("Do you want to close?",
          (IMessageBox::okCancelButton |
           IMessageBox::defButton1 |
           IMessageBox::applicationModal)
        );
      if (result == IMessageBox::ok) {
        return false;
      }
      return true;
    }
    return false;
  }
};

/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif

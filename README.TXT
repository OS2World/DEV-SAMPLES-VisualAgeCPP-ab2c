NAME: AB2C.ZIP

COPYRIGHT:
----------
Copyright (C) International Business Machines Corp., 1991,1995.

DISCLAIMER OF WARRANTIES:
-------------------------
The following [enclosed] code is sample code created by IBM
Corporation.  This sample code is not part of any standard IBM product
and is provided to you solely for the purpose of assisting you in the
development of your applications.  The code is provided "AS IS",
without warranty of any kind.  IBM shall not be liable for any damages
arising out of your use of the sample code, even if they have been
advised of the possibility of such damages.


DESCRIPTION:

Contains a sample of intercepting the CLOSE event of the framewindow in
a Visual Builder application.

You will have to attach a handler to the framewindow, if you want to
intercept the CLOSE event.  In the handlers, I display a message box
prompting for a YES or NO answer.

In the attached zip file, you will find IVBAB2C.HPP which contains the
source code for the handlers.  IVBAB2C.VBE allows you to import the two
handlers.

IVBAboutToCloseHandler is used to intercept the close message for the following
scenarios:

  - Double-click on the system menu button.
  - Select "Close" on the system menu.
  - Press Alt + F4.
  - Select "Close" from the system Window List.

IVBCloseMessageHandler is used to intercept the close message if you call
the IFrameWindow::close() method to close the frame window.
for

An example of attaching the handler(s) to the framewindow:

 - drop the handler(s) on the f/f surface in the compositor editor of a
   visual part.
 - connect the ready event of the visual part to the handler's "start" action
 - connect IFrameWindow::this attribute to the above connection 's window param.



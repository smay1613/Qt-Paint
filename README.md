# Qt-Paint

Implementation of simple paint application with ability to share image in real time.

Features:
* Color picking
* Pen size changing
* Undo/redo actions
* Whiteboard cleanup
* Possibility to draw shapes: 
	-line
	-curve
	-rectangle
	-ellipse
* Zoom
* Workarea streaming (share image via network) - WIP

## Getting Started

1. Run server application.
2. Run paint application with parameters:
	* server-host - Server IP address or a hostname
	* server-port - Server port
	* mode <arguments(slave/master)> - Paint application can work in two modes - slave or master.
					   Master will stream it's painted image to slaves.

### Prerequisites

Qt 5.11 with network module and with Qt Quick. 

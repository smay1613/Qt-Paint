# Qt-Paint

Implementation of simple paint application with ability to share image in real time.

Features:
* Saving image
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
* Changing workarea size
* Workarea streaming (share image via network)

<img src="https://raw.githubusercontent.com/smay1613/Qt-Paint/networking/Preview.png?sanitize=true&raw=true"/>

## Getting Started

1. Run server application.
2. Run paint application with parameters:
	* server-host - Server IP address or a hostname
	* server-port - Server port
	* mode <arguments(slave/master)> - Paint application can work in two modes - slave or master.
					   Master will stream it's painted image to slaves.

## Documentation

Run runDoxygen.sh script for generating the Doxygen documentation.

### Prerequisites

Qt 5.12 with network module and with Qt Quick. 

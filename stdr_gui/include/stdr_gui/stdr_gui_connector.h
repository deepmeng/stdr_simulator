/******************************************************************************
   STDR Simulator - Simple Two DImensional Robot Simulator
   Copyright (C) 2013 STDR Simulator
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
   Authors : 
   * Manos Tsardoulias, etsardou@gmail.com
   * Aris Thallas, aris.thallas@gmail.com
   * Chris Zalidis, zalidis@gmail.com 
******************************************************************************/

#ifndef STDR_GUI_CONNECTOR
#define STDR_GUI_CONNECTOR

#include "stdr_gui/stdr_gui_loader.h"
#include "stdr_gui/stdr_robot_creator/stdr_robot_creator_connector.h"

namespace stdr_gui{
	
	/**
	 @class GuiConnector
	 @brief Serves the Qt events of the main GUI window. Inherits from QObject
	 **/ 
	class GuiConnector:public QObject{
		Q_OBJECT
		
		private:
		
			int argc; 			//!< Number of input arguments
			char **argv;		//!< Input arguments
			bool _mapLoaded;	//!< True if any map is loaded from server
			
		public:
		
			GuiLoader loader;							//!< The loader of main GUI QWidget 
			RobotCreatorConnector robotCreatorConn;		//!< Serves the Qt events of the RobotCreator Widget
			
			/**
			@brief Deafault contructor
			@param argc [int] Number of input arguments
			@param argv [char **] Input arguments
			@return void
			**/
			GuiConnector(int argc, char **argv);
			
			/**
			@brief Setter of _mapLoaded variable
			@param mapLoaded [bool] 
			@return void
			**/
			void setMapLoaded(bool mapLoaded);

		public slots:
		
			/**
			@brief Qt slot that is called when the Properties tool button is pressed
			@return void
			**/
			void actionPropertiesTriggered(void);
			
			/**
			@brief Qt slot that is called when the About tool button is pressed
			@return void
			**/
			void actionAboutTriggered(void);
			
			/**
			@brief Qt slot that is called when the Exit action is triggered
			@return void
			**/
			void actionExitTriggered(void);
			
			/**
			@brief Qt slot that is called when the LoadMap tool button is pressed
			@return void
			**/
			void actionLoadMapTriggered(void);
			
			/**
			@brief Qt slot that is called when the NewRobot tool button is pressed
			@return void
			**/
			void actionNewRobotTriggered(void);
			
			/**
			@brief Qt slot that is called when the zoom in tool button is pressed
			@return void
			**/
			void actionZoomInTriggered(void);
			
			/**
			@brief Qt slot that is called when the zoom out tool button is pressed
			@return void
			**/
			void actionZoomOutTriggered(void);
			
		signals:
		
			/**
			@brief Qt signal that is emmited in GuiConnector::actionZoomInTriggered and connects to MapLoader::setCursorZoomIn
			@param state [bool] Toggle flag
			@return void
			**/
			void setZoomInCursor(bool state);
			
			/**
			@brief Qt signal that is emmited in GuiConnector::actionZoomOutTriggered and connects to MapLoader::setCursorZoomOut
			@param state [bool] Toggle flag
			@return void
			**/
			void setZoomOutCursor(bool state);
	};
}

#endif

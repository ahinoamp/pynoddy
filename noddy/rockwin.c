/*
	This file was generated by XVT-Design 4.5, a product of:

		XVT Software Inc.
		4900 Pearl East Circle
		Boulder, CO USA 80301
		303-443-4223, fax 303-443-0969

	Generated on Tue Sep 02 10:35:00 1997
*/
/* TAG BEGIN SPCL:Pre_Header */
/* TAG END SPCL:Pre_Header */

#include "xvt.h"
#include "xvtcm.h"
#include "nodInc.h"

/* 
	Information about the window
*/
#define WIN_RES_ID ROCK_WINDOW
#define WIN_FLAGS 0x810L
#define WIN_CLASS ""
#define WIN_BORDER W_DOC
/* TAG BEGIN SPCL:Obj_Decl */
/* TAG END SPCL:Obj_Decl */

/*
	Handler for window ROCK_WINDOW ("Rock Properties")
*/
long XVT_CALLCONV1
#if XVT_CC_PROTO
ROCK_WINDOW_eh XVT_CALLCONV2 (WINDOW xdWindow, EVENT *xdEvent)
#else
ROCK_WINDOW_eh XVT_CALLCONV2 (xdWindow, xdEvent)
WINDOW xdWindow;
EVENT *xdEvent;
#endif
{
	short xdControlId = xdEvent->v.ctl.id;
	/* TAG BEGIN SPCL:Var_Decl */
	/* TAG END SPCL:Var_Decl */

	switch (xdEvent->type) {
	case E_CREATE:
		/*
			Window has been created; first event sent to newly-created
			window.
		*/
		{
		/* TAG BEGIN EVNT:Create */
			/* put this window in the created heirachy */
		addWinToStack (xdWindow);
		loadRockPropOptions (xdWindow, (OBJECT *) xvt_vobj_get_data(xdWindow));
		/* TAG END EVNT:Create */
		}
		break;
	case E_DESTROY:
		/*
			Window has been closed; last event sent to window.
		*/
		xdRemoveHelpAssoc( xdWindow );
		{
		/* TAG BEGIN EVNT:Destroy */
			/* take this window out of the created heirachy */
		takeWinFromStack (xdWindow);
		/* TAG END EVNT:Destroy */
		}
		break;
	case E_FOCUS:
		{
		/* TAG BEGIN EVNT:Focus */
		/*
			Window has lost or gained focus.
		*/
		if (xdEvent->v.active) {
			/*
				Window has gained focus
			*/
		} else {
			/*
				Window has lost focus
			*/
		}
		/* TAG END EVNT:Focus */
		}
		break;
	case E_SIZE:
		/*
			Size of window has been set or changed; sent when window is
			created or subsequently resized by user or via xvt_vobj_move.
		*/
		{
		/* TAG BEGIN EVNT:Size */
		/* TAG END EVNT:Size */
		}
		break;
	case E_UPDATE:
		/*
			Window requires updating.
		*/
		{
		/* TAG BEGIN EVNT:Update */
		xvt_dwin_clear(xdWindow, (COLOR)xvt_vobj_get_attr(xdWindow, ATTR_BACK_COLOR));
		/* TAG END EVNT:Update */
		}
		break;
	case E_CLOSE:
		/*
			Request to close window; user operated "close" menu item on
			window system menu, or operated "close" control on window
			frame. Not sent if Close on File menu is issued. Window not
			closed unless xvt_vobj_destroy is called.
		*/
		{
		/* TAG BEGIN EVNT:Close */
		xvt_vobj_destroy(xdWindow);
		/* TAG END EVNT:Close */
		}
		break;
	case E_CHAR:
		/*
			Character typed.
		*/
		{
		/* TAG BEGIN EVNT:Char */
			/* *********************************************** */
			/* make a RETURN key activate the window OK Button */
		if (xdEvent->v.chr.ch == '\r')
		{
		   xdEvent->type = E_CONTROL;
		   xdEvent->v.ctl.id = ROCK_OK;
		   xvt_win_dispatch_event (xdWindow, xdEvent);
		}
		/* TAG END EVNT:Char */
		}
		break;
	case E_MOUSE_UP:
		/*
			Mouse was released
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Up */
		/* TAG END EVNT:Mouse_Up */
		}
		break;
	case E_MOUSE_DOWN:
		/*
			Mouse was pressed
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Down */
		/* TAG END EVNT:Mouse_Down */
		}
		break;
	case E_MOUSE_DBL:
		/*
			Mouse was double clicked
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Dbl */
		/* TAG END EVNT:Mouse_Dbl */
		}
		break;
	case E_MOUSE_MOVE:
		/*
			Mouse was moved
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Move */
		/* TAG END EVNT:Mouse_Move */
		}
		break;
	case E_HSCROLL:
		{
		/* TAG BEGIN EVNT:Hscroll */
		/*
			Horizontal scrollbar on frame was operated
		*/
		switch (xdEvent->v.scroll.what) {
		case SC_LINE_UP:
			break;
		case SC_LINE_DOWN:
			break;
		case SC_PAGE_UP:
			break;
		case SC_PAGE_DOWN:
			break;
		case SC_THUMB:
			break;
		case SC_THUMBTRACK:
			break;
		default:
			break;
		}
		/* TAG END EVNT:Hscroll */
		}
		break;
	case E_VSCROLL:
		{
		/* TAG BEGIN EVNT:Vscroll */
		/*
			Vertical scrollbar on frame was operated
		*/
		switch (xdEvent->v.scroll.what) {
		case SC_LINE_UP:
			break;
		case SC_LINE_DOWN:
			break;
		case SC_PAGE_UP:
			break;
		case SC_PAGE_DOWN:
			break;
		case SC_THUMB:
			break;
		case SC_THUMBTRACK:
			break;
		default:
			break;
		}
		/* TAG END EVNT:Vscroll */
		}
		break;
	case E_COMMAND:
		/*
			User issued command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Command */
		/*
			No menubar was associated with this window
		*/
		/* TAG END EVNT:Command */
		}
		break;
	case E_CONTROL:
		/*
			User operated control in window.
		*/
		{
		/* TAG BEGIN SPCL:Control_Decl */
		/* TAG END SPCL:Control_Decl */

		switch(xdControlId) {
		case ROCK_HEIGHT: /* "5500" */
			{
			/* TAG BEGIN ROCK_HEIGHT EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_HEIGHT EVNT:Control */
			}
			break;
		case ROCK_DENSITY: /* "2.0" */
			{
			/* TAG BEGIN ROCK_DENSITY EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_DENSITY EVNT:Control */
			}
			break;
		case ROCK_INTENSITY: /* "Inten" */
			{
			/* TAG BEGIN ROCK_INTENSITY EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_INTENSITY EVNT:Control */
			}
			break;
		case ROCK_COLOR: /* "Define Colour..." */
			{
			/* TAG BEGIN ROCK_COLOR EVNT:Control */
			OBJECT *data = (OBJECT *) xvt_vobj_get_data (xdWindow);
			WINDOW win;
			if (!(win = createCenteredWindow(DEFINE_COLOUR_WINDOW, TASK_WIN, EM_ALL, DEFINE_COLOUR_WINDOW_eh, (long) data)))
				xvt_dm_post_error("Can't open window");
			/* TAG END ROCK_COLOR EVNT:Control */
			}
			break;
		case ROCK_ANISOTROPY: /* "Anisotropy" */
			{
			/* TAG BEGIN ROCK_ANISOTROPY EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, ROCK_ANISOTROPY);
			BOOLEAN state = (!xvt_ctl_is_checked(ctl_win));
			xvt_ctl_set_checked(ctl_win, (BOOLEAN) state);
						/* enable the options that should be alloud */
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_Y), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_Y_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_Z), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_Z_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DIP), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DIP_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DDIR), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DDIR_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_PITCH), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_PITCH_LABEL), (BOOLEAN) state);
			   
			/* TAG END ROCK_ANISOTROPY EVNT:Control */
			}
			break;
		case ROCK_REMANENCE: /* "Remanence" */
			{
			/* TAG BEGIN ROCK_REMANENCE EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, ROCK_REMANENCE);
			int state = (!xvt_ctl_is_checked(ctl_win));
			xvt_ctl_set_checked(ctl_win, (BOOLEAN) state);
						/* enable the options that should be alloud */
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DECLINATION), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_DECLINATION_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_INCLINATION), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_INCLINATION_LABEL), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_INTENSITY), (BOOLEAN) state);
			xvt_vobj_set_enabled (xvt_win_get_ctl (xdWindow, ROCK_INTENSITY_LABEL), (BOOLEAN) state);
			 
			/* TAG END ROCK_REMANENCE EVNT:Control */
			}
			break;
		case ROCK_X: /* "x" */
			{
			/* TAG BEGIN ROCK_X EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_X EVNT:Control */
			}
			break;
		case ROCK_Y: /* "y" */
			{
			/* TAG BEGIN ROCK_Y EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_Y EVNT:Control */
			}
			break;
		case ROCK_Z: /* "z" */
			{
			/* TAG BEGIN ROCK_Z EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_Z EVNT:Control */
			}
			break;
		case ROCK_DECLINATION: /* "dec" */
			{
			/* TAG BEGIN ROCK_DECLINATION EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_DECLINATION EVNT:Control */
			}
			break;
		case ROCK_INCLINATION: /* "incl" */
			{
			/* TAG BEGIN ROCK_INCLINATION EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_INCLINATION EVNT:Control */
			}
			break;
		case ROCK_DIP: /* "dip" */
			{
			/* TAG BEGIN ROCK_DIP EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_DIP EVNT:Control */
			}
			break;
		case ROCK_DDIR: /* "dip dir" */
			{
			/* TAG BEGIN ROCK_DDIR EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_DDIR EVNT:Control */
			}
			break;
		case ROCK_PITCH: /* "pitch" */
			{
			/* TAG BEGIN ROCK_PITCH EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END ROCK_PITCH EVNT:Control */
			}
			break;
		case ROCK_NAME: /* "name" */
			{
			/* TAG BEGIN ROCK_NAME EVNT:Control */
			/*
				Listedit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/*
					Contents of control were changed
				*/
				updatePropertiesOptions (xdWindow);
			}
			/* TAG END ROCK_NAME EVNT:Control */
			}
			break;
		case ROCK_OK: /* "OK" */
			{
			/* TAG BEGIN ROCK_OK EVNT:Control */
						/* ********************************** */
						/* save all the options in the window */
			saveRockPropOptions (xdWindow, (OBJECT *) xvt_vobj_get_data(xdWindow));
			xvt_vobj_destroy(xdWindow);
			/* TAG END ROCK_OK EVNT:Control */
			}
			break;
		case ROCK_CANCEL: /* "Cancel" */
			{
			/* TAG BEGIN ROCK_CANCEL EVNT:Control */
			OBJECT *data = (OBJECT *) xvt_vobj_get_data (xdWindow);
			copyOptions (PROFILE_WINDOW, data, OPTIONS_RESTORE);
			xvt_vobj_destroy(xdWindow);
			/* TAG END ROCK_CANCEL EVNT:Control */
			}
			break;
		case ROCK_HELP: /* "Help..." */
			{
			/* TAG BEGIN ROCK_HELP EVNT:Control */
			displayHelp("rock.htm");
			/* TAG END ROCK_HELP EVNT:Control */
			}
			break;
		case ROCK_ALTER: /* "Alter" */
			{
			/* TAG BEGIN ROCK_ALTER EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, ROCK_ALTER);
			xvt_ctl_set_checked(ctl_win, (BOOLEAN) (!xvt_ctl_is_checked(ctl_win)));
			/* TAG END ROCK_ALTER EVNT:Control */
			}
			break;
		case ROCK_WIDTH: /* "widthval" */
			{
			/* TAG BEGIN ROCK_WIDTH EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/*
					Contents of control were changed
				*/
				double layerWidth, origWidth, difference;
				LAYER_PROPERTIES *layer;
			
				layerWidth = getFloatTextFieldValue (xdWindow, ROCK_WIDTH);
				origWidth = getLayerWidth ((OBJECT *) xvt_vobj_get_data (xdWindow));
			
				difference = layerWidth - origWidth;
				
				if (layer = (LAYER_PROPERTIES *) getLayerPropertiesStructure ((OBJECT *) xvt_vobj_get_data (xdWindow)))
				{
					updateNumericTextField (xdWindow, ROCK_HEIGHT, (int) (layer->height - difference));
				}
			}
			/* TAG END ROCK_WIDTH EVNT:Control */
			}
			break;
		default:
			break;
		}
		}
		break;
	case E_FONT:
		/*
			User issued font command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Font */
		/* TAG END EVNT:Font */
		}
		break;
	case E_TIMER:
		/*
			Timer associated with window went off.
		*/
		{
		/* TAG BEGIN EVNT:Timer */
		/* TAG END EVNT:Timer */
		}
		break;
	case E_USER:
		/*
			Application initiated.
		*/
		{
		/* TAG BEGIN EVNT:User */
		switch (xdEvent->v.user.id) {
		case -1:
		default:
			break;
		}
		/* TAG END EVNT:User */
		}
		break;
	default:
		break;
	}
	/* TAG BEGIN SPCL:Bottom */
#ifdef XVT_R40_TXEDIT_BEHAVIOR
	xvt_tx_process_event(xdWindow, xdEvent);
#endif
	/* TAG END SPCL:Bottom */
	return 0L;
}

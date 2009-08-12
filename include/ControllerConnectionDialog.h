/*
 * ControllerConnectionDialog.h - dialog allowing the user to create and
 *	modify links between controllers and models
 *
 * Copyright (c) 2008  Paul Giblock <drfaygo/at/gmail.com>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef _CONTROLLER_CONNECTION_DIALOG_H
#define _CONTROLLER_CONNECTION_DIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QSortFilterProxyModel>
#include <QtGui/QStandardItemModel>

#include "Controller.h"
#include "automatable_model.h"


class QLineEdit;
class QListView;
class QScrollArea;
class AutoDetectMidiController;
class comboBox;
class groupBox;
class tabWidget;
class lcdSpinBox;
class ledCheckBox;
class MidiPortMenu;



class ControllerConnectionDialog : public QDialog
{
	Q_OBJECT
public:
	ControllerConnectionDialog( QWidget * _parent,
			const automatableModel * _target_model );
	virtual ~ControllerConnectionDialog();

	Controller * chosenController( void )
	{
		return m_controller;
	}

public slots:
//	void setSelection( const effectKey & _selection );
	void selectController( void );
	void midiToggled( void );
	void userToggled( void );
	void autoDetectToggled( void );
	void enableAutoDetect( QAction * _a );


protected slots:
	void midiValueChanged( void );


private:
	// Midi
	groupBox * m_midiGroupBox;
	lcdSpinBox * m_midiChannelSpinBox;
	lcdSpinBox * m_midiControllerSpinBox;
	ledCheckBox * m_midiAutoDetectCheckBox;
	MidiPortMenu * m_readablePorts;
	boolModel m_midiAutoDetect;

	// User
	groupBox * m_userGroupBox;
	comboBox * m_userController;

	// Mapping
	tabWidget * m_mappingBox;
	QLineEdit * m_mappingFunction;

	Controller * m_controller;
	const automatableModel * m_targetModel;

	// Temporary midiController 
	AutoDetectMidiController * m_midiController;
} ;

#endif

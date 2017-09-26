/*
 *  QOffice: Office UI framework for Qt
 *  Copyright (C) 2016-2017 Nicolas Kogler
 *
 *  This file is part of QOffice.
 *
 *  QOffice is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  QOffice is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with QOffice. If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef QOFFICE_OFFICEMENUEDITORDIALOG_HPP
#define QOFFICE_OFFICEMENUEDITORDIALOG_HPP


// QOffice headers
#include <QOffice/Widgets/OfficeMenu.hpp>

// Qt headers
#include <QDialog>
#include <QtDesigner/QDesignerFormWindowInterface>
#include <QtDesigner/QDesignerFormWindowCursorInterface>
#include <QTreeWidget>
#include <QListWidget>
#include <QStackedWidget>


QOFFICE_BEGIN_NAMESPACE


/**
 * The dialog in which the office menu can be customized.
 *
 * @class OfficeMenuEditorDialog
 * @author Nicolas Kogler
 * @date January 1st, 2016
 *
 */
class QOFFICE_EXPORT OfficeMenuEditorDialog : public QDialog
{
public:

    /**
     * Initializes a new instance of OfficeMenuEditorDialog.
     *
     * @param menu The menu to be edited.
     * @param parent The parent of this dialog.
     *
     */
    OfficeMenuEditorDialog(OfficeMenu* menu, QWidget* parent = nullptr);

    /**
     * Frees all resources used by OfficeMenuEdiorDialog.
     *
     */
    ~OfficeMenuEditorDialog();


    /**
     * Retrieves the perfect size for this widget.
     *
     * @returns the perfect size.
     *
     */
    QSize sizeHint() const;


private slots:

    void clearAllItems();
    void saveAllItems();
    void addTopMenuItem();
    void addPanel();
    void addMenuItem();
    void addItem(QAction*);
    void removePanel();
    void removeTopMenuItem();
    void removeItem();
    void saveCurrentItem();
    void addDropDownItem();
    void addTextboxDropDownItem();
    void removeDropDownItem();
    void removeTextboxDropDownItem();
    void putDropDownItemUp();
    void putTextboxDropDownItemUp();
    void putDropDownItemDown();
    void putTextboxDropDownItemDown();
    void saveDropDownItem();
    void saveTextboxDropDownItem();
    void onTreeViewItemChange();
    void onDropDownItemChange(QListWidgetItem*);
    void onTextboxDropDownItemChange(QListWidgetItem*);
    void showTreeViewContextMenu(QPoint pos);
    int determineTreeWidgetItemType();


private:

    // Members
    OfficeMenu*  m_OldMenu;
    OfficeMenu*  m_NewMenu;
    QWidget*     m_Form;
    QTreeWidget* m_Tree;
    QListWidget* m_List;
    QListWidget* m_TbList;
    QStackedWidget* m_Stack;

    // Selected items
    QTreeWidgetItem *m_SelectedTreeItem;
    QListWidgetItem *m_SelectedDropDownItem;
    QListWidgetItem *m_SelectedTextboxDropDownItem;
    QList<QAction*>  m_CurrentMenuActions;

    // Metadata
    Q_OBJECT
};


QOFFICE_END_NAMESPACE


#endif // QOFFICE_OFFICEMENUEDITORDIALOG_HPP
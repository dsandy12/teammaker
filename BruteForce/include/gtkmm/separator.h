// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SEPARATOR_H
#define _GTKMM_SEPARATOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtkmm/widget.h>
#include <gtkmm/orientable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSeparator = struct _GtkSeparator;
using GtkSeparatorClass = struct _GtkSeparatorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class Separator_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A separator widget.
 *
 * Gtk::Separator is a horizontal or vertical separator widget, depending on the
 * value of the orientation property, used to group the widgets within a
 * window. It displays a line with a shadow to make it appear sunken into the
 * interface.
 */

class Separator
 : public Widget,
   public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Separator CppObjectType;
  typedef Separator_Class CppClassType;
  typedef GtkSeparator BaseObjectType;
  typedef GtkSeparatorClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Separator(Separator&& src) noexcept;
  Separator& operator=(Separator&& src) noexcept;

  // noncopyable
  Separator(const Separator&) = delete;
  Separator& operator=(const Separator&) = delete;

  ~Separator() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Separator_Class;
  static CppClassType separator_class_;

protected:
  explicit Separator(const Glib::ConstructParams& construct_params);
  explicit Separator(GtkSeparator* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkSeparator*       gobj()       { return reinterpret_cast<GtkSeparator*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkSeparator* gobj() const { return reinterpret_cast<GtkSeparator*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:

  //Note that we try to use the same default parameter value as the default property value.
    explicit Separator(Orientation orientation =  ORIENTATION_HORIZONTAL);


};

} //namespace Gtk

//Include the deprecated header,
//whose classes were previously in this header,
//to preserve the "API" of the includes.
#include <gtkmm/hvseparator.h>


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Separator
   */
  Gtk::Separator* wrap(GtkSeparator* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_SEPARATOR_H */


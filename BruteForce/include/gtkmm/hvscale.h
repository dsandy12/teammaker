// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_HVSCALE_H
#define _GTKMM_HVSCALE_H


#ifndef GTKMM_DISABLE_DEPRECATED


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

#include <gtkmm/scale.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkVScale = struct _GtkVScale;
using GtkVScaleClass = struct _GtkVScaleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class VScale_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkHScale = struct _GtkHScale;
using GtkHScaleClass = struct _GtkHScaleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class HScale_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A vertical slider for selecting values.
 *
 * The Gtk::VScale widget is used to allow the user to select a value using a
 * vertical slider. See the Gtk::Scale documentation for more information
 * on how to use a Gtk::VScale.
 *
 * A VScale widget looks like this:
 * @image html vscale1.png
 *
 * @ingroup Widgets
 *
 * @deprecated Use Scale instead.
 */

class VScale : public Scale
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VScale CppObjectType;
  typedef VScale_Class CppClassType;
  typedef GtkVScale BaseObjectType;
  typedef GtkVScaleClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  VScale(VScale&& src) noexcept;
  VScale& operator=(VScale&& src) noexcept;

  // noncopyable
  VScale(const VScale&) = delete;
  VScale& operator=(const VScale&) = delete;

  ~VScale() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class VScale_Class;
  static CppClassType vscale_class_;

protected:
  explicit VScale(const Glib::ConstructParams& construct_params);
  explicit VScale(GtkVScale* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkVScale*       gobj()       { return reinterpret_cast<GtkVScale*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkVScale* gobj() const { return reinterpret_cast<GtkVScale*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  VScale();

  /**
  * Construct a VScale with the given minimum and maximum. The step size is the
  * distance the slider moves when the arrow keys are used to adjust the scale
  * value.
  */
  VScale(double min, double max, double step);
  explicit VScale(const Glib::RefPtr<Adjustment>& adjustment);


};

/** A horizontal slider for selecting values.
 *
 * The Gtk::HScale widget is used to allow the user to select a value using a
 * horizontal slider. See the Gtk::Scale documentation for more information
 * on how to use a Gtk::HScale.
 *
 * The HScale widget looks like this:
 * @image html hscale1.png
 *
 * @ingroup Widgets
 *
 * @deprecated Use Scale instead.
 */

class HScale : public Scale
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HScale CppObjectType;
  typedef HScale_Class CppClassType;
  typedef GtkHScale BaseObjectType;
  typedef GtkHScaleClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  HScale(HScale&& src) noexcept;
  HScale& operator=(HScale&& src) noexcept;

  // noncopyable
  HScale(const HScale&) = delete;
  HScale& operator=(const HScale&) = delete;

  ~HScale() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class HScale_Class;
  static CppClassType hscale_class_;

protected:
  explicit HScale(const Glib::ConstructParams& construct_params);
  explicit HScale(GtkHScale* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkHScale*       gobj()       { return reinterpret_cast<GtkHScale*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkHScale* gobj() const { return reinterpret_cast<GtkHScale*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  HScale();
  /**
  * Construct a HScale with the given minimum and maximum. The step size is the
  * distance the slider moves when the arrow keys are used to adjust the scale
  * value.
  */
  HScale(double min, double max, double step);
  explicit HScale(const Glib::RefPtr<Adjustment>& adjustment);


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::VScale
   */
  Gtk::VScale* wrap(GtkVScale* object, bool take_copy = false);
} //namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::HScale
   */
  Gtk::HScale* wrap(GtkHScale* object, bool take_copy = false);
} //namespace Glib


#endif // GTKMM_DISABLE_DEPRECATED


#endif /* _GTKMM_HVSCALE_H */


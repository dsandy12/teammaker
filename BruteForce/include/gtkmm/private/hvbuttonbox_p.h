// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_HVBUTTONBOX_P_H
#define _GTKMM_HVBUTTONBOX_P_H
#ifndef GTKMM_DISABLE_DEPRECATED


#include <gtkmm/private/buttonbox_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class VButtonBox_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VButtonBox;
  using BaseObjectType = GtkVButtonBox;
  using BaseClassType = GtkVButtonBoxClass;
  using CppClassParent = Gtk::ButtonBox_Class;
  using BaseClassParent = GtkButtonBoxClass;

  friend class VButtonBox;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <glibmm/class.h>

namespace Gtk
{

class HButtonBox_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = HButtonBox;
  using BaseObjectType = GtkHButtonBox;
  using BaseClassType = GtkHButtonBoxClass;
  using CppClassParent = Gtk::ButtonBox_Class;
  using BaseClassParent = GtkButtonBoxClass;

  friend class HButtonBox;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk

#endif // GTKMM_DISABLE_DEPRECATED


#endif /* _GTKMM_HVBUTTONBOX_P_H */


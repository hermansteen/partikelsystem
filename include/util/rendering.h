#ifndef __RENDERING_H__
#define __RENDERING_H__

#include "color.h"
#include <string>
#include <vector>

/// This namespace contains objects that are helper functions that support the rendering
/// of general ui elements, particles, emitters, and forces.
namespace rendering {

/*
 * These following structures are passed to the update functions further down in this file
 * to render the individual objects. Each of the update functions take a vector of these
 * structs which are then rendered in the next call to the render function
 */

/// The struct that represents an individual particle that is to be rendered to screen
struct ParticleInfo {
    /// The position of the particle. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    float x = 0.f;
    float y = 0.f;

    /// The size of the particle. This size is expressed roughly in pixels
    float radius = 2.f;

    /// The color of the particle. Each color component has to be in the range [0, 1]
    Color color = Color(1.f, 0.8f, 0.2f);

    /// The remaining lifetime of the particle in seconds
    float lifetime = 60.f;
};

/// The struct that represents an individual emitter location that is to be rendered. Note
/// that some emitters might not have a physical location and might not require a
/// corresponding EmitterInfo struct
struct EmitterInfo {
    /// The position of the emitter. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    float x = 0.f;
    float y = 0.f;

    /// The size of the rectangle that is used to represent the emitter in pixels
    float size = 12.5f;

    /// The color of the emitter. Each color component has to be in the range [0, 1]
    Color color = Color(0.2f, 1.f, 0.8f);
};

/// The struct that represents an individual force location that is to be rendered. Note
/// that some forces might not have a physical location and might not require a
/// corresponding ForceInfo struct
struct ForceInfo {
    /// The position of the force. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    float x = 0.f;
    float y = 0.f;

    // Size of the triangle that is used to represent the force in pixels
    float size = 12.5f;

    // The color for the force. Each color component has to be in the range [0, 1]
    Color color = Color(0.8f, 0.2f, 1.f);
};

/**
 * This function creates the rendering window and initializes all the necessary background
 * state. This function must only be called once per application.
 *
 * \throw std::runtime_error If there was a compilation error with a shader
 * \pre This function has not been called before
 */
void createWindow();

/**
 * This function destroys the rendering window and the associated background state. This
 * function must only be called once at the end of the application. After this function
 * has been called, no other function in this file must be called anymore.
 *
 * \pre This function has not been called before
 */
void destroyWindow();

/**
 * Sets the background color that is used for clearing the window.
 *
 * \param r The red channel of the background color in the range [0, 1]
 * \param g The green channel of the background color in the range [0, 1]
 * \param b The blue channel of the background color in the range [0, 1]

 * \pre \p r must be in the range [0, 1]
 * \pre \p g must be in the range [0, 1]
 * \pre \p b must be in the range [0, 1]
 */
void setBackgroundColor(float r, float g, float b);

/**
 * Sets up the initial frame state and must be called in the beginning of the frame. It
 * will poll and respond to all the keyboard and mouse input and set up the user interface
 * that can be called during the frame.
 *
 * \return The time that has passed since the beginning of the last frame in seconds
 *         (= delta time, dt)
 */
[[ nodiscard ]] float beginFrame();

/**
 * Updates the internal list of particles that will be rendered in the next #render call.
 * Unless this function is called again, the same values are used in all subsequent calls
 * until a new call to updateParticles is made.
 * 
 * \param particles The information about the particles that are rendered in the next call
 *        to the render function
 * \pre The createWindow function has been called exactly once in the application
 * \pre The beginFrame has been called since the beginning of this frame
 */
void updateParticles(const std::vector<ParticleInfo>& particles);

/**
 * Updates the internal list of emitters that will be rendered in the next #render call.
 * Unless this function is called again, the same values are used in all subsequent calls
 * until a new call to updateParticles is made.
 *
 * \param emitters The information about the emitters that are rendered in the next call
 *        to the render function
 * \pre The createWindow function has been called exactly once in the application
 * \pre The beginFrame has been called since the beginning of this frame
 */
void updateEmitters(const std::vector<EmitterInfo>& emitters);

/**
 * Updates the internal list of forces that will be rendered in the next #render call.
 * Unless this function is called again, the same values are used in all subsequent calls
 * until a new call to updateParticles is made.
 *
 * \param forces The information about the forces that are rendered in the next call to
 *        the render function
 * \pre The createWindow function has been called exactly once in the application
 * \pre The beginFrame has been called since the beginning of this frame
 */
void updateForces(const std::vector<ForceInfo>& forces);

/**
 * This function renders all of the particles, emitters, and forces that were passed in
 * the last call to updateParticles. updateEmitters, and updateForces respectively. It
 * also renders the user interface elements to the screen
 */
void render();

/**
 * Finalizes the current frame and swaps the front and back buffers for double buffering.
 * The function returns whether the render loop should continue or if the user requested
 * that the window should close.
 *
 * \return \c true if the rendering should continue, \c false if the rendering should end
 */
[[ nodiscard ]] bool endFrame();

} // namespace rendering

/**
 * This namespace contains helper classes that can be used to create user interfaces. Most
 * of the classes operate in a similar fashion; you create an instance of the class for
 * the duration of the application. In the render loop you call the objects render method.
 * In most cases the function returns \c true if the user interacted with the UI (pressed
 * a button, changed a value, etc) and the variable(s) passed as parameters to the
 * function are changed if the user interacted with the element).
 *
 * The one exception to this is the Group object, which will create a group in the
 * beginning of its lifetime and will close the group at the end of the lifetime.
 * For example:
 * ui::Text t;
 * ui::Button b("bar");
 * {
 *   ui::Group g("Foo");
 *   t.render("Foo text");
 * }
 * {
 *   ui::Group g("Bar");
 *   bool pressed = b.render();
 * }
 *
 * Will create two separate groups, Foo and Bar
 */
namespace ui {

/// This UI element shows a simple text in the user interface
class Text {
public:
    /**
     * Renders the provided \p text to the UI
     *
     * \param The text that should be rendered
     *
     * \pre \p text must not be empty
     */
    void render(std::string text);
};

/**
 * A group that lives for the lifetime of this object with the provided name \p text. You
 * can create a local variable in the beginning of a scope and simply render UI elements
 * in the scope.
 */
class Group {
public:
    /**
     * Creates the group with a specific name \p text.
     *
     * \param text The name of the group
     * \pre \p text must not be empty
     */
    Group(std::string text);
    ~Group();
};

/// A slider UI element that can be moved between a given minimum and maximum value. The 
/// values of the slider are floating point values.
class FloatSlider {
public:
    /**
     * Creates the slider with the provided \p text and the minimum value of \p minValue
     * and maximum value of \p maxValue.
     *
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     * \pre \p minValue must be smaller than \p maxValue
     */
    FloatSlider(const char* text, float minValue, float maxValue);

    /**
     * Renders the slider into the UI. If the user changed the value for the slider, the
     * return value will be \c true and \p value contains the changed value. If the user
     * did not interact with the slider, the value passed to \p value will not be
     * modified.
     *
     * \param value The in/out parameter for the value displayed by the slider
     * \return \c true if the user interacted with the slider, \c false otherwise
     */
    bool render(float& value);

private:
    /// The text displayed next to the slider
    const char* _text;
    /// The minimum value allowed by the slider
    float _minValue;
    /// The maximum value allowed by the slider
    float _maxValue;
};

/// A slider UI element that can be moved between a given minimum and maximum value. The
/// values of the slider are integral values.
class IntSlider {
public:
    /**
     * Creates the slider with the provided \p text and the minimum value of \p minValue
     * and maximum value of \p maxValue.
     *
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     * \pre \p minValue must be smaller than \p maxValue
     */
    IntSlider(const char* text, int minValue, int maxValue);

    /**
     * Renders the slider into the UI. If the user changed the value for the slider, the
     * return value will be \c true and \p value contains the changed value. If the user
     * did not interact with the slider, the value passed to \p value will not be
     * modified.
     *
     * \param value The in/out parameter for the value displayed by the slider
     * \return \c true if the user interacted with the slider, \c false otherwise
     */
    bool render(int& value);

private:
    /// The text displayed next to the slider
    const char* _text;
    /// The minimum value allowed by the slider
    int _minValue;
    /// The maximum value allowed by the slider
    int _maxValue;
};

/// A double slider UI element that can be moved between a given minimum and maximum
/// value. This element shows two sliders that are each showing floating point values.
class Vec2Slider {
public:
    /**
     * Creates the slider with the provided \p text and the minimum value of \p minValue
     * and maximum value of \p maxValue. The same \p minValue and \p maxValue are used for
     * both sliders.
     *
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     * \pre \p minValue must be smaller than \p maxValue
     */
    Vec2Slider(const char* text, float minValue, float maxValue);

    /**
     * Renders the slider into the UI. If the user changed the value for the slider, the
     * return value will be \c true and \p value contains the changed value. If the user
     * did not interact with the slider, the value passed to \p value will not be
     * modified.
     *
     * \param value The in/out parameter for the value displayed by the slider
     * \return \c true if the user interacted with the slider, \c false otherwise
     */
    bool render(float& x, float& y);

private:
    /// The text displayed next to the slider
    const char* _text;
    /// The minimum value allowed by the slider
    float _minValue;
    /// The maximum value allowed by the slider
    float _maxValue;
};

/// A UI element that provides a way to select colors using an easier to use interface.
class Color {
public:
    /**
     * Creates the color picker ui element the provided \p text
     *
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     */
    Color(const char* text);

    /**
     * Renders the color picker into the UI. If the user changed the color, the return
     * value will be \c true and \p r, \p g, and \p b contain the color components of the
     * new color. If the user did not interact with the picker, the values passed to
     * \p r, \p g, and \p b will not be modified.
     *
     * \param r The in/out parameter for the color's red component in the range [0, 1]
     * \param g The in/out parameter for the color's green component in the range [0, 1]
     * \param b The in/out parameter for the color's blue component in the range [0, 1]
     * \return \c true if the user picked a new color, \c false otherwise
     */
    bool render(float& r, float& g, float& b);

private:
    /// The text that is shown alongside the color picker
    const char* _text;
};

/// This UI element represents a button that can be clicked by the user.
class Button {
public:
    /**
     * Creates a new button with the provided \p text.
     *
     * \param text The text that is written inside the button
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     */
    Button(const char* text);

    /**
     * Renders the button to the UI. If the user pressed the button, this function returns
     * \c true, otherwise, \c false is returned.
     *
     * \return \c true if the user pressed the button, \c false otherwise
     */
    [[ nodiscard ]] bool render();

private:
    /// The text that is shown inside the button
    const char* _text;
};

/// This UI element represents a checkbox that can be selected or deselected by the user
class Checkbox {
public:
    /**
     * Creates the checkbox with the provided \p text.
     *
     * \param text The text that is shown next to the checkbox
     * \pre \p text must not be a nullptr
     * \pre \p text must not be empty
     */
    Checkbox(const char* text);

    /**
     * Renders the checkbox to the UI. If the user changed the state of the checkbox, 
     * this method returns \c true and the new state of the checkbox is writted into the
     * \p value parameter. If the user did not change the state of the checkbox, this
     * method returns \c false and the value passed to \p value remains unchanged.
     *
     * \param value The in/out parameter that represents the state whether the checkbox is
     *        selected or not
     * \return \c true if the user changed the state of the checkbox, \c false otherwise
     */
    bool render(bool& value);

private:
    /// The text that is shown next to the checkbox
    const char* _text;
};

} // namespace ui

#endif // __RENDERING_H__

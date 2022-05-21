enum EasingFunctions{
        // Linear interpolation (no easing)
    linear,

    // Quadratic easing; p^2
    easeInQuadratic,
    easeOutQuadratic,
    easeInOutQuadratic,

    // Cubic easing; p^3
    easeInCubic,
    easeOutCubic,
    easeInOutCubic,

    // Quartic easing; p^4
    easeInQuartic,
    easeOutQuartic,
    easeInOutQuartic,

    // Quintic easing; p^5
    easeInQuintic,
    easeOutQuintic,
    easeInOutQuintic,

    // Sine wave easing; sin(p * PI/2)
    easeInSine,
    easeOutSine,
    easeInOutSine,

    // Circular easing; sqrt(1 - p^2)
    easeInCircular,
    easeOutCircular,
    easeInOutCircular,

    // Exponential easing, base 2
    easeInExponential,
    easeOutExponential,
    easeInOutExponential,

    // Exponentially-damped sine wave easing
    easeInElastic,
    easeOutElastic,
    easeInOutElastic,

    // Overshooting cubic easing; 
    easeInBack,
    easeOutBack,
    easeInOutBack,

    // Exponentially-decaying bounce easing
    easeInBounce,
    easeOutBounce,
    easeInOutBounce,

    easeInOutSineEaseInOut
};
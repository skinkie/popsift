#pragma once

namespace popart
{

struct Config
{
    Config( );

    enum SiftMode {
        OpenCV,
        VLFeat
    };

    enum LogMode {
        None,
        All
    };

    enum ScalingMode {
        DirectOctaves,
        DownscaledOctaves
    };

    void setModeVLFeat( float sigma = 0.82f );
    void setModeOpenCV( float sigma = 1.6f );
    void setLogMode( LogMode mode = All );
    void setScalingMode( ScalingMode mode = DownscaledOctaves );
    void setVerbose( bool on = true );

    void setUpsampling( float v );
    void setOctaves( int v );
    void setLevels( int v );
    void setSigma( float v );
    void setEdgeLimit( float v );
    void setThreshold( float v );

    // determine the image format of the first octave
    // relative to the input image's size (x,y) as follows:
    // (x / 2^start_sampling, y / 2^start_sampling )
    float    start_sampling;

    // The number of octaves is chosen freely. If not specified,
    // it is: log_2( min(x,y) ) - 3 - start_sampling
    int      octaves;

    // The number of levels per octave. This is actually the
    // number of inner DoG levels where we can search for
    // feature points. The number of ...
    int      levels;
    float    sigma;

    // default edge_limit 16.0f from Celebrandil
    // default edge_limit 10.0f from Bemap
    float    edge_limit;

    // default threshold 0.0 default of vlFeat
    // default threshold 5.0 / 256.0
    // default threshold 15.0 / 256.0 - it seems our DoG is really small ???
    // default threshold 5.0 from Celebrandil, not happening in our data
    // default threshold 0.04 / (_levels-3.0) / 2.0f * 255
    //                   from Bemap -> 1.69 (makes no sense)
    float    threshold;

    // default SiftMode::OpenCV
    SiftMode sift_mode;

    // default LogMode::None
    LogMode  log_mode;

    // default: ScalingMode::DownscaledOctaves
    ScalingMode scaling_mode;

    bool     verbose;
};

}; // namespace popart

// バージョン取得
//#define CV_VERSION_STR CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)
#define CV_VERSION_STR "320"
#define CV_DIR_LIB ".\\dependencies\\opencv-3.2.0\\x64\\vc14\\lib\\"

// ビルドモード
#ifdef _DEBUG
#define CV_EXT_LIB "d.lib"
#else
#define CV_EXT_LIB ".lib"
#endif

// ライブラリのリンク（不要な物はコメントアウト）
#pragma comment(lib, CV_DIR_LIB "opencv_calib3d"    CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_core"       CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_features2d" CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_flann"      CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_highgui"    CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_imgcodecs"  CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_imgproc"    CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_ml"         CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_objdetect"  CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_photo"      CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_shape"      CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_stitching"  CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_superres"   CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_video"      CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_videoio"    CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_videostab"  CV_VERSION_STR CV_EXT_LIB)
#pragma comment(lib, CV_DIR_LIB "opencv_viz"        CV_VERSION_STR CV_EXT_LIB)

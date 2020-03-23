/**********************************************************************
 *
 * Copyright (C) 2019 Aware, Inc.
 *
 * $Workfile:  $    $Revision:  $
 * Last Modified: $Date: $ by: $Author:  $
 *
 **********************************************************************/

/* DO NOT EDIT THIS FILE. IT IS AUTO-GENERATED */ 


#ifndef _AW_PREFACE_ERRORS_H_
#define _AW_PREFACE_ERRORS_H_

/* Error Codes */

/* No errors or warnings. */
#define AW_PREFACE_E_NO_ERRORS                              0

/* Internal error. */
#define AW_PREFACE_E_INTERNAL_ERROR                         1

/* The library failed to allocate memory. */
#define AW_PREFACE_E_OUT_OF_MEMORY                          100

/* The preface object was NULL. */
#define AW_PREFACE_E_NULL_PREFACE_OBJ                       101

/* The image format is not supported. */
#define AW_PREFACE_E_IMAGE_FORMAT_NOT_SUPPORTED             104

/* An invalid face detection mode was given. */
#define AW_PREFACE_E_INVALID_FACE_DETECTION_MODE            105

/* An invalid color format was given. */
#define AW_PREFACE_E_INVALID_COLOR_FORMAT                   106

/* An invalid width was given. */
#define AW_PREFACE_E_INVALID_WIDTH                          107

/* An invalid height was given. */
#define AW_PREFACE_E_INVALID_HEIGHT                         108

/* An invalid stride was given. */
#define AW_PREFACE_E_INVALID_STRIDE                         109

/* An image has not been successfully loaded yet. */
#define AW_PREFACE_E_NO_IMAGE_LOADED                        110

/* The face index specified exceeds the number of faces found. */
#define AW_PREFACE_E_INVALID_FACE_INDEX                     111

/* The metric specified is not a valid metric. */
#define AW_PREFACE_E_INVALID_METRIC                         112

/* Compliance scale factor should be greater than or equal to 1.0. */
#define AW_PREFACE_E_INVALID_COMPLIANCE_SCALE               113

/* Failed to parse image. */
#define AW_PREFACE_E_PARSING_IMAGE                          114

/* This metric doesn't have correctable value. */
#define AW_PREFACE_E_NO_CORRECTABLE_VALUE                   115

/* The given image does not meet the minimum image size requirements. */
#define AW_PREFACE_E_IMAGE_TOO_SMALL                        116

/* Only 8 bit greyscale and 24 bit RGB/BGR images are supported. */
#define AW_PREFACE_E_INVALID_BIT_DEPTH                      117

/* Only 0, 90, 180, and 270 clockwise are supported for image rotation
   angle. */
#define AW_PREFACE_E_INVALID_ROTATION_ANGLE                 118

/* The image buffer size does not match the image dimensions. */
#define AW_PREFACE_E_INVALID_IMAGE_BUFFER_SIZE              119

/* A query was attempted on an invalid facial feature. */
#define AW_PREFACE_E_INVALID_FEATURE                        120

/* A query was attempted with an invalid box type. */
#define AW_PREFACE_E_INVALID_BOX_TYPE                       121

/* The specified minimum size is outside the valid range of [0, 1]. */
#define AW_PREFACE_E_INVALID_MINIMUM_SIZE                   122

/* The specified maximum size is outside the valid range of [0, 1]. */
#define AW_PREFACE_E_INVALID_MAXIMUM_SIZE                   123

/* The specified sensitivity is outside the valid range of [0, 1]. */
#define AW_PREFACE_E_INVALID_SENSITIVITY                    124

/* The specified granularity is outside the valid range of [0, 1]. */
#define AW_PREFACE_E_INVALID_GRANULARITY                    125

/* The specified maximum size is less than the specified minimum size. */
#define AW_PREFACE_E_INVALID_RELATIVE_SIZE                  126

/* The given face handle is not valid. */
#define AW_PREFACE_E_INVALID_FACE_HANDLE                    127

/* The metric value is not within allowed range. */
#define AW_PREFACE_E_INVALID_METRIC_VALUE                   128

/* The given profile handle is not valid. */
#define AW_PREFACE_E_INVALID_PROFILE_HANDLE                 129

/* The given value does not match an existing metric. */
#define AW_PREFACE_E_PROFILE_METRIC_VALUE_INVALID           130

/* The given compliance status is not valid. */
#define AW_PREFACE_E_INVALID_COMPLIANCE_STATUS              131

/* The given index is not valid. */
#define AW_PREFACE_E_INVALID_INDEX                          132

/* The given profile metric is not valid. */
#define AW_PREFACE_E_PROFILE_METRIC_INVALID                 133

/* The metric unit in the profiel is not valid. */
#define AW_PREFACE_E_PROFILE_METRIC_UNIT_INVALID            134

/* The metric in the profile is in the wrong category. */
#define AW_PREFACE_E_PROFILE_METRIC_IN_WRONG_CATEGORY       135

/* An error occurred parsing the profile. */
#define AW_PREFACE_E_PARSING_PROFILE_FILE                   136

/* An error occurred validating the profile. */
#define AW_PREFACE_E_VALIDATING_PROFILE_FILE                137

/* The profile is not supported by this version of PreFace. */
#define AW_PREFACE_E_PROFILE_VERSION_INCOMPATIBLE           138

/* The profile is not valid. */
#define AW_PREFACE_E_INVALID_PROFILE                        139

/* The metric constraint specified is invalid. */
#define AW_PREFACE_E_INVALID_METRIC_CONSTRAINT              140

/* The metric category in the profile is invalid. */
#define AW_PREFACE_E_PROFILE_METRIC_CATEGORY_INVALID        141

/* The name of the metric in the profile is invalid. */
#define AW_PREFACE_E_PROFILE_METRIC_NAME_INVALID            142

/* Invalid image height to width ratio */
#define AW_PREFACE_E_INVALID_HEIGHT_TO_WIDTH_RATIO          143

/* Invalid image width to head width ratio */
#define AW_PREFACE_E_INVALID_IMAGEWIDTH_TO_HEADWIDTH_RATIO  144

/* Image resolution is too low for specified eye separation */
#define AW_PREFACE_E_IMAGE_RESOLUTION_TOO_LOW_FOR_EYESEPARATION 145

/* Specified/computed eye separation is out of valid range */
#define AW_PREFACE_E_INVALID_EYE_SEPARATION                 146

/* Original image width is too small for full frontal trimming based on
   input image width to head width ratio */
#define AW_PREFACE_E_IMAGEWIDTH_TOO_SMALL_FOR_RATIO         147

/* Original image height is too small for full frontal trimming based on
   input height to width ratio */
#define AW_PREFACE_E_IMAGEHEIGHT_TOO_SMALL_FOR_RATIO        148

/* Invalid location of eye-axis. */
#define AW_PREFACE_E_INVALID_EYE_AXIS_LOCATION              149

/* Invalid head height to image height ratio. */
#define AW_PREFACE_E_INVALID_HEADHEIGHT_TO_IMAGEHEIGHT_RATIO 150

/* Face cannot be centered without padding. */
#define AW_PREFACE_E_FACE_CENTER_UNCORRECTABLE_WITHOUT_PADDING 151

/* Image width to head width ratio cannot be corrected without padding. */
#define AW_PREFACE_E_IMAGEWIDTH_TO_HEADWIDTH_UNCORRECTABLE_WITHOUT_PADDING 152

/* Head height to image height ratio cannot be corrected without padding. */
#define AW_PREFACE_E_HEADHEIGHT_TO_IMAGEHEIGHT_UNCORRECTABLE_WITHOUT_PADDING 153

/* Eye axis location ratio cannot be corrected without padding. */
#define AW_PREFACE_E_EYE_AXIS_LOCATION_UNCORRECTABLE_WITHOUT_PADDING 154

/* Full frontal image cannot be generated without padding. */
#define AW_PREFACE_E_UNCORRECTABLE_WITHOUT_PADDING          155

/* Image width and image width to head width ratio are inconsistent. */
#define AW_PREFACE_E_INCONSISTENT_IMAGEWIDTH_RATIO          156

/* Image height and head height to image height ratio are inconsistent. */
#define AW_PREFACE_E_INCONSISTENT_IMAGEHEIGHT_RATIO         157

/* Fewer constraints should be specified in compliance config file. */
#define AW_PREFACE_E_TOO_MANY_CONSTRAINTS                   158

/* More constraints need to be specified in compliance config file. */
#define AW_PREFACE_E_TOO_FEW_CONSTRAINTS                    159

/* Constraints are inconsistent in compliance config file. */
#define AW_PREFACE_E_INCONSISTENT_CONSTRAINTS               160

/* Eye axis location ratio must be constrained. */
#define AW_PREFACE_E_UNCONSTRAINED_EYE_AXIS_LOCATION_RATIO  163

/* Unable to define head boundary for accurate background fill. */
#define AW_PREFACE_E_FILL_UNDEFINED_HEAD_BOUNDARY           166

/* Unable to define lower neck and/or shoulder boundary for accurate
   background fill. */
#define AW_PREFACE_E_FILL_UNDEFINED_SHOULDER_BOUNDARY       167

/* Create full frontal failed. */
#define AW_PREFACE_E_CONSTRUCT_FAILED                       169

/* The given compliance handle is not valid. */
#define AW_PREFACE_E_INVALID_COMPLIANCE_HANDLE              170

/* The given pointer is null. */
#define AW_PREFACE_E_NULL_POINTER                           171

/* The value specified is less than the minimum allowed for the specified
   Metric. */
#define AW_PREFACE_E_METRIC_CONSTRAINT_VALUE_TOO_LOW        172

/* The value specified is greater than the maximum allowed for the specified
   Metric. */
#define AW_PREFACE_E_METRIC_CONSTRAINT_VALUE_TOO_HIGH       173

/*  The minimum value is greater than the maximum value. */
#define AW_PREFACE_E_MIN_GREATER_THAN_MAX                   178

/* The minimum value is greater than the preferred value. */
#define AW_PREFACE_E_MIN_GREATER_THAN_PREF                  179

/* The preferred value is greater than the max value. */
#define AW_PREFACE_E_PREF_GREATER_THAN_MAX                  180

/* The correctable minimum value is greater than the correctable maximum
   value. */
#define AW_PREFACE_E_CMIN_GREATER_THAN_CMAX                 185

/* The qWeight should be equal to or greather than zero. */
#define AW_PREFACE_E_NEGATIVE_QWEIGHT                       186

/* Invalid number of channels. */
#define AW_PREFACE_E_INVALID_NUM_CHANNELS                   187

/* The J2K compressed image size is out of the valid range. */
#define AW_PREFACE_E_COMPRESSED_IMAGE_SIZE_OUT_OF_RANGE     188

/* The ROI foreground compression ratio is out of the valid range. */
#define AW_PREFACE_E_ROI_FOREGROUND_COMPRESSION_RATIO_OUT_OF_RANGE 189

/* The ROI background compression ratio is out of the valid range. */
#define AW_PREFACE_E_ROI_BACKGROUND_COMPRESSION_RATIO_OUT_OF_RANGE 190

/* The achieved ROI foreground compression ratio is greater than the maximum
   ratio specified. */
#define AW_PREFACE_E_ROI_FOREGROUND_COMPRESSION_RATIO_OUT_OF_EXCEEDED 191

/* The J2K dll is absent. */
#define AW_PREFACE_E_J2K_DLL_ABSENT                         193

/* Invalid value specified for max levle of enhancement. */
#define AW_PREFACE_E_INVALID_MAX_LEVEL_ENHANCE              194

/* Enhancement of ROI compressed JPEG2000 images not supported. */
#define AW_PREFACE_E_ENHANCE_J2KROI_NOT_SUPPORT             195

/* Eye locations are invalid. x coordinate for left eye should be greater
   than right eye. */
#define AW_PREFACE_E_EYE_LOCATIONS_INVALID                  196

/* The metric score requested could not be returned due to an error in
   calculation. */
#define AW_PREFACE_E_ERROR_CALCULATING_SCORE                197

/* Could not detect a face with eye locations at the specified points. */
#define AW_PREFACE_E_NO_FACE_DETECTED_FROM_EYE_LOCATIONS    198

/* Suspected background fill error due to uncertain head boundary. */
#define AW_PREFACE_E_FILL_UNCERTAIN_HEAD_BOUNDARY           200

/* Suspected background fill error due to uncertain shoulder boundary. */
#define AW_PREFACE_E_FILL_UNCERTAIN_SHOULDER_BOUNDARY       201

/* Suspected background fill error due to undercertain neck boundary. */
#define AW_PREFACE_E_FILL_UNCERTAIN_NECK_BOUNDARY           202

/* Likely background fill error due to background complexity. */
#define AW_PREFACE_E_FILL_BACKGROUND_TOO_COMPLEX            203

/* Image cannot be made compliant by enhancement. */
#define AW_PREFACE_E_UNABLE_TO_ENHANCE_TO_COMPLIANCE        204

/* Image is out of correctable range, so no enhancement performed. */
#define AW_PREFACE_E_NO_ENHANCE_OUT_CORRECTABLE_RANGE       206

/* The Image Property specified is invalid. */
#define AW_PREFACE_E_INVALID_IMAGE_PROPERTY                 207

/* The specified value is not valid for the specified property. */
#define AW_PREFACE_E_INVALID_PROPERTY_VALUE                 208

/* The data record format specified is not supported. */
#define AW_PREFACE_E_INVALID_DATA_RECORD_FORMAT             300

/* The JSON string data could not be read. */
#define AW_PREFACE_E_INVALID_JSON_STRING                    301

/* The data record could not be encoded due to a formatting error. */
#define AW_PREFACE_E_DATA_RECORD_ENCODE_FAILURE             302

/* The data recrod could not be decoded due to a formatting error. */
#define AW_PREFACE_E_DATA_RECORD_DECODE_FAILURE             303

/* The attribute library handle provided was invalid. */
#define AW_PREFACE_E_ATTRIBUTE_INVALID_HANDLE_PROVIDED      702

/* A null pointer was passed to the attribute library. */
#define AW_PREFACE_E_ATTRIBUTE_NULL_POINTER_PARAMETER       703

/* The specified classifier data file was either corrupt or invalid.  Please
   use the file provided with the PreFace 6 Library. */
#define AW_PREFACE_E_CLASSIFIER_DATA_FILE_INVALID           800

/* The classifier data file has already been set for this process. */
#define AW_PREFACE_E_CLASSIFIER_DATA_FILE_PREVIOUSLY_SET    801

/* Cannot initialize PreFace without the Classifier Data File set. */
#define AW_PREFACE_E_CLASSIFIER_DATA_FILE_NOT_SET           802

/* Cannot initialize the number of classifiers specified. */
#define AW_PREFACE_E_INVALID_CLASSIFIER_COUNT               803

/*  */
#define AW_PREFACE_E_FINDER_NULL_POINTER_PARAMETER          804

/* Classifier initialization was unsuccessful. */
#define AW_PREFACE_E_NULL_CLASSIFIER                        805

/* The function call made or its parameters are not supported in Mobile
   mode. */
#define AW_PREFACE_E_UNSUPPORTED_IN_MOBILE_MODE             806

/*  */
#define AW_PREFACE_E_FINDER_INVALID_HANDLE_PROVIDED         808

/* Failed to parse the JSON request. */
#define AW_PREFACE_E_FAILED_TO_PARSE_JSON                   10001

/* The function name was not valid. */
#define AW_PREFACE_E_INVALID_FUNCTION_NAME                  10002

/* The parameter list must be a JSON array. */
#define AW_PREFACE_E_INVALID_PARAMETER_LIST                 10003

/* A parameter had an incorrect type. */
#define AW_PREFACE_E_INVALID_PARAMETER_TYPE                 10004

/* The wrong number of parameters were passed to the function. */
#define AW_PREFACE_E_INCORRECT_PARAMETER_COUNT              10005

/* The channel name is incorrect, hasn't been opened, or is closed. */
#define AW_PREFACE_E_INVALID_CHANNEL_NAME                   10006



#endif /* _AW_PREFACE_ERRORS_H_ */

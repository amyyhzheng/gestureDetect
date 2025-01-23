/*
* DEEPCRAFT Studio 5.2.2135+b54b28f236fe7c6fb520f00b8de0ba1419f4422f
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 01/23/2025 16:39:48 UTC. Any changes will be lost.
* 
* Model ID  302a77f1-6928-48f1-99f4-5e787a2d2aa6
* 
* Memory    Size                      Efficiency
* Buffers   6000 bytes (RAM)          80 %
* State     808 bytes (RAM)           100 %
* Readonly  32972 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-0
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | up
* 2           | down
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [50,3]          float      dequeue
*    window_shape = [50,3]
*    stride = 15
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [50,3]          float      dequeue
*    contextual_length_sec = 1
*    prediction_freq = 10
* Input Layer                    [50,3]          float      dequeue
*    shape = [50,3]
* Convolution 1D                 [25,12]         float      dequeue
*    filters = 12
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,12]
* Batch Normalization            [25,12]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[12]
*    beta = float[12]
*    mean = float[12]
*    variance = float[12]
* Activation                     [25,12]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,24]         float      dequeue
*    filters = 24
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,12,24]
* Convolution 1D                 [25,24]         float      dequeue
*    filters = 24
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,24,24]
* Batch Normalization            [25,24]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[24]
*    beta = float[24]
*    mean = float[24]
*    variance = float[24]
* Activation                     [25,24]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,24]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [12,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,24,32]
* Convolution 1D                 [12,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [12,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [12,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [6,32]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [3]             float      dequeue
*    units = 3
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,3]
*    bias = float[3]
* Activation                     [3]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[3].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[3].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 63.095 %
* (F1S) F1 Score 48.818 %
* 
* Name of class                                            (unlabelled)             down               up
* (TP) True Positive or Correct Positive Prediction                  53                0                0
* (FN) False Negative or Incorrect Negative Prediction                0               17               14
* (FP) False Positive or Incorrect Positive Prediction               31                0                0
* (TN) True Negative or Correct Negative Prediction                   0               67               70
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %           0.00 %           0.00 %
* (TNR) True Negative Rate or Specificity, Selectivity           0.00 %         100.00 %         100.00 %
* (PPV) Positive Predictive Value or Precision                  63.10 %         100.00 %         100.00 %
* (NPV) Negative Predictive Value                              100.00 %          79.76 %          83.33 %
* (FNR) False Negative Rate or Miss Rate                         0.00 %         100.00 %         100.00 %
* (FPR) False Positive Rate or Fall-Out                        100.00 %           0.00 %           0.00 %
* (FDR) False Discovery Rate                                    36.90 %         100.00 %         100.00 %
* (FOR) False Omission Rate                                    100.00 %          20.24 %          16.67 %
* (F1S) F1 Score                                                77.37 %           0.00 %           0.00 %
*/


#define IMAI_TEST_AVG_ACC 0.6309523809523809 // Accuracy
#define IMAI_TEST_AVG_F1S 0.4881821341675357 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 53, FN: 0, FP: 31, TN: 0, TPR: 1, TNR: 0, PPV: 0.6309523809523, NPV: 1, FNR: 0, FPR: 1, FDR: 0.3690476190476, FOR: 1, F1S: 0.7737226277372, }, \
 {name: "up", TP: 0, FN: 14, FP: 0, TN: 70, TPR: 0, TNR: 1, PPV: 1, NPV: 0.8333333333333, FNR: 1, FPR: 0, FDR: 1, FOR: 0.1666666666666, F1S: 0, }, \
 {name: "down", TP: 0, FN: 17, FP: 0, TN: 67, TPR: 0, TNR: 1, PPV: 1, NPV: 0.7976190476190, FNR: 1, FPR: 0, FDR: 1, FOR: 0.2023809523809, F1S: 0, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 93.043 %
* (F1S) F1 Score 92.777 %
* 
* Name of class                                            (unlabelled)             down               up
* (TP) True Positive or Correct Positive Prediction                 410                3               15
* (FN) False Negative or Incorrect Negative Prediction               18               13                1
* (FP) False Positive or Incorrect Positive Prediction               14                0               18
* (TN) True Negative or Correct Negative Prediction                  18              444              426
* (TPR) True Positive Rate or Sensitivity, Recall               95.79 %          18.75 %          93.75 %
* (TNR) True Negative Rate or Specificity, Selectivity          56.25 %         100.00 %          95.95 %
* (PPV) Positive Predictive Value or Precision                  96.70 %         100.00 %          45.45 %
* (NPV) Negative Predictive Value                               50.00 %          97.16 %          99.77 %
* (FNR) False Negative Rate or Miss Rate                         4.21 %          81.25 %           6.25 %
* (FPR) False Positive Rate or Fall-Out                         43.75 %           0.00 %           4.05 %
* (FDR) False Discovery Rate                                     3.30 %           0.00 %          54.55 %
* (FOR) False Omission Rate                                     50.00 %           2.84 %           0.23 %
* (F1S) F1 Score                                                96.24 %          31.58 %          61.22 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9304347826086956 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9277683316856571 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 410, FN: 18, FP: 14, TN: 18, TPR: 0.9579439252336, TNR: 0.5625, PPV: 0.9669811320754, NPV: 0.5, FNR: 0.0420560747663, FPR: 0.4375, FDR: 0.0330188679245, FOR: 0.5, F1S: 0.9624413145539, }, \
 {name: "up", TP: 15, FN: 1, FP: 18, TN: 426, TPR: 0.9375, TNR: 0.9594594594594, PPV: 0.4545454545454, NPV: 0.9976580796252, FNR: 0.0625, FPR: 0.0405405405405, FDR: 0.5454545454545, FOR: 0.0023419203747, F1S: 0.6122448979591, }, \
 {name: "down", TP: 3, FN: 13, FP: 0, TN: 444, TPR: 0.1875, TNR: 1, PPV: 1, NPV: 0.9715536105032, FNR: 0.8125, FPR: 0, FDR: 0, FOR: 0.0284463894967, F1S: 0.3157894736842, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 90.873 %
* (F1S) F1 Score 86.528 %
* 
* Name of class                                            (unlabelled)             down               up
* (TP) True Positive or Correct Positive Prediction                 229                0                0
* (FN) False Negative or Incorrect Negative Prediction                0               12               11
* (FP) False Positive or Incorrect Positive Prediction               23                0                0
* (TN) True Negative or Correct Negative Prediction                   0              240              241
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %           0.00 %           0.00 %
* (TNR) True Negative Rate or Specificity, Selectivity           0.00 %         100.00 %         100.00 %
* (PPV) Positive Predictive Value or Precision                  90.87 %         100.00 %         100.00 %
* (NPV) Negative Predictive Value                              100.00 %          95.24 %          95.63 %
* (FNR) False Negative Rate or Miss Rate                         0.00 %         100.00 %         100.00 %
* (FPR) False Positive Rate or Fall-Out                        100.00 %           0.00 %           0.00 %
* (FDR) False Discovery Rate                                     9.13 %         100.00 %         100.00 %
* (FOR) False Omission Rate                                    100.00 %           4.76 %           4.37 %
* (F1S) F1 Score                                                95.22 %           0.00 %           0.00 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9087301587301587 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8652773652773653 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 229, FN: 0, FP: 23, TN: 0, TPR: 1, TNR: 0, PPV: 0.9087301587301, NPV: 1, FNR: 0, FPR: 1, FDR: 0.0912698412698, FOR: 1, F1S: 0.9521829521829, }, \
 {name: "up", TP: 0, FN: 11, FP: 0, TN: 241, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9563492063492, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0436507936507, F1S: 0, }, \
 {name: "down", TP: 0, FN: 12, FP: 0, TN: 240, TPR: 0, TNR: 1, PPV: 1, NPV: 0.9523809523809, FNR: 1, FPR: 0, FDR: 1, FOR: 0.0476190476190, F1S: 0, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "up", "down"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xf1, 0x77, 0x2a, 0x30, 0x28, 0x69, 0xf1, 0x48, 0x99, 0xf4, 0x5e, 0x78, 0x7a, 0x2d, 0x2a, 0xa6}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [3] (12 bytes)
#define IMAI_DATA_IN_COUNT (3)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [3] (12 bytes)
#define IMAI_DATA_OUT_COUNT (3)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (39)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */

#ifndef LGLOBAL_H
#define LGLOBAL_H

#include <QtCore/QtGlobal>

#define L_DECLARE_PRIVATE(Class) \
    friend class Class##Private; \
    class Class##Private * const dp;

#define L_DECLARE_JOB(Class) \
    friend class Class##Job; \
    class Class##Job * const dj;

#endif // LGLOBAL_H

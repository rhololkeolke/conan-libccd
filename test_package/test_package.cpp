#include <ccd/ccd.h>
#include <ccd/quat.h>
#include <iostream>

#define CCD_OBJ_CYL 3

#define __CCD_OBJ__                                                            \
  int type;                                                                    \
  ccd_vec3_t pos;                                                              \
  ccd_quat_t quat;

struct _ccd_cyl_t {
  __CCD_OBJ__
  ccd_real_t radius;
  ccd_real_t height;
};
typedef struct _ccd_cyl_t ccd_cyl_t;

#define CCD_BOX(name)                                                          \
  ccd_box_t name = {.type = CCD_OBJ_BOX,                                       \
                    .pos = {.v = {0., 0., 0.}},                                \
                    .quat = {.q = {0., 0., 0., 1.}},                           \
                    .x = 0.,                                                   \
                    .y = 0.,                                                   \
                    .z = 0.}

#define CCD_SPHERE(name)                                                       \
  ccd_sphere_t name = {.type = CCD_OBJ_SPHERE,                                 \
                       .pos = {.v = {0., 0., 0.}},                             \
                       .quat = {.q = {0., 0., 0., 1.}},                        \
                       .radius = 0.}

#define CCD_CYL(name)                                                          \
  ccd_cyl_t name = {.type = CCD_OBJ_CYL,                                       \
                    .pos = {.v = {0., 0., 0.}},                                \
                    .quat = {.q = {0., 0., 0., 1.}},                           \
                    .radius = 0.,                                              \
                    .height = 0.}

int main() {
  ccd_t ccd;
  CCD_CYL(c1);
  CCD_CYL(c2);

  c1.radius = 0.35;
  c1.height = 0.5;
  c2.radius = 0.5;
  c2.height = 1.;

  return 0;
}

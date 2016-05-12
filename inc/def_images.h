#ifndef __def_images_H__
#define __def_images_H__
/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#define IMAGE_DIR "/opt/usr/apps/org.example.scrollview/res/images/"

const char* IMAGE_PATHS[] = {
    IMAGE_DIR "gallery-medium-1.jpg",
    IMAGE_DIR "gallery-medium-2.jpg",
    IMAGE_DIR "gallery-medium-3.jpg",
    IMAGE_DIR "gallery-medium-4.jpg",
    IMAGE_DIR "gallery-medium-5.jpg",
    IMAGE_DIR "gallery-medium-6.jpg",
    IMAGE_DIR "gallery-medium-7.jpg",
    IMAGE_DIR "gallery-medium-8.jpg",
    IMAGE_DIR "gallery-medium-9.jpg",
    IMAGE_DIR "gallery-medium-10.jpg",
    IMAGE_DIR "gallery-medium-11.jpg",
    IMAGE_DIR "gallery-medium-12.jpg",
    IMAGE_DIR "gallery-medium-13.jpg",
    IMAGE_DIR "gallery-medium-14.jpg"
};
const unsigned int NUM_IMAGES = sizeof(IMAGE_PATHS) / sizeof(char*);

#endif // __def_images_H__

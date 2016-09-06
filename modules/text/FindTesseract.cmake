# Tesseract OCR
unset(Tesseract_FOUND)

if(MINGW)
  set(MINGW_DIR C:/MinGW/mingw32)
  set(MINGW_LIB_DIR ${MINGW_DIR}/lib)
  set(LEPTONICA_DIR D:/git/share)
endif()
  
find_path(Tesseract_INCLUDE_DIR tesseract/baseapi.h
  HINTS
  /usr/include
  /usr/local/include)

find_library(Tesseract_LIBRARY NAMES tesseract
  HINTS
  /usr/lib
  /usr/local/lib)

find_library(Lept_LIBRARY NAMES lept
  HINTS
  ${LEPTONICA_DIR}/lib
  /usr/lib
  /usr/local/lib)

if(MINGW)
  find_library(WS2_32_LIB NAMES libws2_32.a
                              PATHS 
                              ${MINGW_LIB_DIR}
                              NO_DEFAULT_PATH
                              NO_SYSTEM_ENVIRONMENT_PATH)
  set(Tesseract_LIBS ${Tesseract_LIBRARY} ${Lept_LIBRARY} ${WS2_32_LIB})
else()
  set(Tesseract_LIBS ${Tesseract_LIBRARY} ${Lept_LIBRARY})
endif()

if(Tesseract_LIBS AND Tesseract_INCLUDE_DIR)
    set(Tesseract_FOUND 1)
endif()

        

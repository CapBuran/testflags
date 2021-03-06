function(download_github_com_latest url tag_link filedst)
  if(NOT EXISTS ${CMAKE_BINARY_DIR}/ThreeParty)
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/ThreeParty)
  endif(NOT EXISTS ${CMAKE_BINARY_DIR}/ThreeParty)
  if(NOT EXISTS ${CMAKE_BINARY_DIR}/ThreeParty/latest.txt)
    file(DOWNLOAD ${url} ${CMAKE_BINARY_DIR}/ThreeParty/latest.txt)
  endif(NOT EXISTS ${CMAKE_BINARY_DIR}/ThreeParty/latest.txt)
  file(READ ${CMAKE_BINARY_DIR}/ThreeParty/latest.txt _download_latest_txt)
  string(REGEX MATCHALL "(\"${tag_link}\":[^,]+)(http[^\"\",]+\)" _real_url_download ${_download_latest_txt})
  string(FIND ${_real_url_download} "http" _real_url_download_begin)
  string(LENGTH ${_real_url_download} _real_url_download_end)
  string(SUBSTRING ${_real_url_download} ${_real_url_download_begin} ${_real_url_download_end} _real_url_download)
  message("-- Download: " ${_real_url_download})
  if(NOT EXISTS ${CMAKE_SOURCE_DIR}/ThreeParty/${filedst})
    file(DOWNLOAD ${_real_url_download} ${CMAKE_SOURCE_DIR}/ThreeParty/${filedst})
  else(${CMAKE_SOURCE_DIR}/ThreeParty/${filedst})
    return()
  endif(NOT EXISTS ${CMAKE_SOURCE_DIR}/ThreeParty/${filedst})
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_SOURCE_DIR}/ThreeParty/${filedst}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ThreeParty
  )
  #message("-- Download2: ${CMAKE_COMMAND} -E tar xvzf ${CMAKE_BINARY_DIR}/ThreeParty/${filedst}")

endfunction()
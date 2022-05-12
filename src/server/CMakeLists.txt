add_library(server_lib ./server.cpp)                    # .cpp file path

target_include_directories(server_lib PUBLIC .)         # path to catalog that contain
                                                        # .hpp file
                                                        # (not directly to .hpp file!)
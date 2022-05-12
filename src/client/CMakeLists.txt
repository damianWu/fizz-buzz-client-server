add_library(client_lib ./client.cpp)                    # .cpp file path

target_include_directories(client_lib PUBLIC .)         # path to catalog that contain
                                                        # .hpp file
                                                        # (not directly to .hpp file!)
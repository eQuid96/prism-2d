namespace prism
{

#define prism_log_error(msg)                                \
    {                                                       \
        std::cerr << "[Prism Error]: " << msg << std::endl; \
    }
}  // namespace prism
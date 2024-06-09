namespace SDLUtils {
    /// Counts how many bits an integer uses.
    template<typename T>
    size_t countBitsTaken(T val) noexcept {
        size_t i = 0;
        while (val != 0) {
            val = val >> 1;
            i++;
        }
        return i;
    }
}

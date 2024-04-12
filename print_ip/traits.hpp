
namespace print_ip {

template <typename T>
concept has_begin_end = requires(T cont) {
  cont.begin();
  cont.end();
};

template <typename T, template <typename...> class TT>
constexpr bool is_instantiation_of_v = false;

template <template <typename...> class TT, typename... TS>
constexpr bool is_instantiation_of_v<TT<TS...>, TT> = true;

template <class C, template <typename...> class TT>
concept instantiation_of = is_instantiation_of_v<C, TT>;

}  // namespace print_ip

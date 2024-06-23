//       _   _     _                                   //
//   ___| |_| | __| |_   _ _ __ ___  _ __   ___ _ __   //
//  / __| __| |/ _` | | | | '_ ` _ \| '_ \ / _ \ '__|  //
//  \__ \ |_| | (_| | |_| | | | | | | |_) |  __/ |     //
//  |___/\__|_|\__,_|\__,_|_| |_| |_| .__/ \___|_|     //
//                                  |_|                //

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v);
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &t);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_multimap<T, Y> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v);
template <class T>
ostream &_orange(ostream &_ostr, const T &_v) {
  _ostr << "[";
  for (bool tr = true; auto &i : _v)
    _ostr << (tr ? tr = false, "" : ", ") << i;
  return _ostr << "]";
}
template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v) { return _orange(_ostr, _v); }
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) { return _ostr << "(" << _v.first << ", " << _v.second << ")"; }
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  bool tr = true;
  _ostr << "(";
  apply([&_ostr, &tr](auto &&...args) {
    auto print = [&](auto &&val) {
      if (!tr)
        _ostr << ", ";
      _ostr << val;
      tr = false;
    };
    (print(args), ...);
  },
        _v);
  return _ostr << ")";
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) { return _orange(_ostr, _v); }
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v) { return _orange(_ostr, _v); }
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v);
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v);
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v);
template <class T>
istream &_irange(istream &_istr, T &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v) { return _irange(_istr, _v); }
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v) { return _irange(_istr, _v); }
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v) { return _istr >> _v.first >> _v.second; }

/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words,
convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current
directory. Furthermore, a double period .. moves the directory up a level. For
more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and
there must be only a single slash / between two directory names. The last
directory name (if it exists) must not end with a trailing /. Also, the
canonical path must be the shortest string representing the absolute path.

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:

Input: "/a/./b/../../c/"
Output: "/c"

Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

 */

#include "../util/common.hpp"

class Solution {
public:
  enum class State {
    SLASH, ONE_DOT, TWO_DOTS, DIR_NAME
  };

  string simplifyPath(string path) {
    auto output = deque<string>();
    auto state = State::SLASH;
    auto buffer = stringstream();
    path.push_back('/');
    for (auto i = 1; i < path.length(); i++) {
      auto ch = path[i];
      switch (state) {
      case State::SLASH:
        if (ch == '/') ;
        else if (ch == '.') state = State::ONE_DOT;
        else {
          state = State::DIR_NAME;
          buffer << ch;
        }
        break;
      case State::ONE_DOT:
        if (ch == '.') state = State::TWO_DOTS;
        else if (ch == '/') state = State::SLASH;
        else {
          buffer << "." << ch;
          state = State::DIR_NAME;
        }
        break;
      case State::TWO_DOTS:
        if (ch == '/') {
          if (!output.empty()) {
            output.pop_back();
          }
          state = State::SLASH;
        }
        else {
          buffer << ".." << ch;
          state = State::DIR_NAME;
        }
        break;
      case State::DIR_NAME:
        if (ch == '/') {
          output.push_back(buffer.str());
          buffer.str("");
          buffer.clear();
          state = State::SLASH;
        }
        else buffer << ch;
        break;
      }
    }
    stringstream result;
    if (output.empty()) {
      result << "/";
    }
    else {
      for (auto part: output) {
        result << "/" << part;
      }
    }
    return result.str();
  }
};

void run(string path, string expected) {
  cout << "Input: " << path << endl;
  auto result = Solution().simplifyPath(path);
  cout << "Result: " << result << endl;
  cout << "Expected: " << expected << endl;
  assert(result == expected);
}

int main() {
  run("/home/", "/home");
  run("/../", "/");
  run("/home//foo/", "/home/foo");
  run("/a/./b/../../c/", "/c");
  run("/a/../../b/../c//.//", "/c");
  run("/a//b////c/d//././/..", "/a/b/c");
  run("/...", "/...");
  run("/.hidden", "/.hidden");

  return 0;
}

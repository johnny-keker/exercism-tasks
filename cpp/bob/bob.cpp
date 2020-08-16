#include "bob.h"
#include <cstddef>

namespace bob {

std::string whitespaces (" \t\f\v\n\r");

bool is_question(std::string phrase) {
  std::size_t found = phrase.find_last_not_of(whitespaces);
  return found != std::string::npos && phrase[found] == '?';
}

bool is_yelling(std::string phrase) {
  int alpha = 0;

  for (int i = 0; i < (int)phrase.length(); ++i)
  {
    if (isalpha(phrase[i]) && !isupper(phrase[i]))
      return false;
    if (isalpha(phrase[i]))
      alpha++; 
  }

  return alpha != 0;
}

bool is_silence(std::string phrase) {
  for (int i = 0; i < (int)phrase.length(); ++i)
    if (!isspace(phrase[i]))
      return false;
  
  return true;
}

std::string hey(std::string phrase) {
  bool question = is_question(phrase);
  bool yelling = is_yelling(phrase);
  bool silence = is_silence(phrase);

  if (silence)
    return "Fine. Be that way!";
  else if (question && yelling)
    return "Calm down, I know what I'm doing!";
  else if (yelling)
    return "Whoa, chill out!";
  else if (question)
    return "Sure.";

  return "Whatever.";
}

}  // namespace bob

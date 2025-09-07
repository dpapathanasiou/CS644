#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

// copy of https://github.com/iafisher/cs644/blob/master/week1/switch.c

enum LanguageCode
{
  LANG_EN, // English
  LANG_FR, // French
  LANG_RU, // Russian
};

struct Language
{
  enum LanguageCode code;
  bool has_verb_conjugations;
  bool has_grammatical_gender;
  bool has_noun_declensions;
};

struct Language make_language(enum LanguageCode code)
{
  struct Language lang = {
      .code = code,
      .has_verb_conjugations = false,
      .has_grammatical_gender = false,
      .has_noun_declensions = false,
  };

  switch (code)
  {
  case LANG_RU:
    lang.has_noun_declensions = true;
  case LANG_FR:
    lang.has_verb_conjugations = true;
    lang.has_grammatical_gender = true;
    break;
  case LANG_EN:
    lang.has_verb_conjugations = true;
    break;
  }

  return lang;
}

char *print_human_readable_boolean(bool value)
{
  return value ? "True" : "False";
}

void print_language(struct Language language)
{
  printf("Code:\t%d\n", language.code);
  printf("(Noun Declensions, Verb Conjugations, Grammatical Gender) -> (%s, %s, %s)\n",
         print_human_readable_boolean(language.has_noun_declensions),
         print_human_readable_boolean(language.has_verb_conjugations),
         print_human_readable_boolean(language.has_grammatical_gender));
}

int main()
{
  struct Language russian = make_language(LANG_RU);
  print_language(russian);

  return 0;
}

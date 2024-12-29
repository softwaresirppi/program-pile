#include <string>
#include <map>
#include <array>
#include <iostream>

#include "../potions/butter_spelling.hpp"
#include "../potions/choco.hpp"

size_t findAndReplace(std::string& x, const std::string& findString, const std::string& replaceString, int findFrom = 0) {
  if (findString == replaceString) return -1;
  size_t suspectIndex = x.find(findString.c_str(), findFrom);
  if (suspectIndex == std::string::npos) return -1;
  x.replace(suspectIndex, findString.size(), replaceString);
  return suspectIndex;
}
void findAndReplaceAll(std::string& x, const std::string& findString, const std::string& replaceString, int findFrom = 0) {
#if DEBUG > 0
  output("finding and replacing all ");
  output(findString);
  output(" in ");
  outputLine(x);
#endif
  size_t lastSuspectIndex = findFrom;
  while (findAndReplace(x, findString, replaceString, lastSuspectIndex) != std::string::npos);
}

using DictionaryEntry = std::pair<std::string, std::string>;
const std::array<DictionaryEntry, 45> butterDictionary = {

  // https://www.dyslexia-reading-well.com/44-phonemes-in-english.html{"e", "e"},	//Went, intend, send, letter, bet.
  DictionaryEntry
  {"ɪəʳ", "ear"},   // eer, ere, ier	ear, steer, here, tier
  { "ʊəʳ",	"oor" },   // our	cure, tourist
  { "eɪ", "ei" },   // ai, eigh, aigh, ay, er, et, ei, au, a_e, ea, ey	bay, maid, weigh, straight, pay, foyer, filet, eight, gauge, mate, break, they
  { "i:", "ee" },    // ee, ea, y, ey, oe, ie, i, ei, eo, ay	be, bee, meat, lady, key, phoenix, grief, ski, deceive, people, quay
  { "aɪ", "ai" },   // y, igh, ie, uy, ye, ai, is, eigh, i_e	spider, sky, night, pie, guy, stye, aisle, island, height, kite
  { "oʊ", "ou" },   // oa, o_e, oe, ow, ough, eau, oo, ew	open, moat, bone, toe, sow, dough, beau, brooch, sew
  { "u:", "oo" },    // oo, ew, ue, u_e, oe, ough, ui, oew, ou	who, loon, dew, blue, flute, shoe, through, fruit, manoeuvre, group
  { "ɔɪ", "oy" },    // oy, uoy	join, boy, buoy
  { "aʊ", "ow" },    // ou, ough	now, shout, bough
  { "eəʳ",	"air" },   // are, ear, ere, eir, ayer	chair, dare, pear, where, their, prayer
  { "ɑ:", "aaw" },	    //arm
  { "ɜ:", "ir" },	    //ir, er, ur, ear, or, our, yr	bird, term, burn, pearl, word, journey, myrtle
  { "ɔ:", "aw" },   // a, or, oor, ore, oar, our, augh, ar, ough, au	paw, ball, fork, poor, fore, board, four, taught, war, bought, sauce
  { "æ", "ae" },   // ai, au	cat, plaid, laugh
  { "e",	"e" },   // ea, u, ie, ai, a, eo, ei, ae	end, bread, bury, friend, said, many, leopard, heifer, aesthetic
  { "ɪ",	"i" },   // e, o, u, ui, y, ie	it, england, women, busy, guild, gym, sieve
  { "ɒ",	"aw" },   // ho, au, aw, ough	swan, honest, maul, slaw, fought
  { "ʊ",	"o" },   // oo, u,ou	wolf, look, bush, would
  { "ʌ",	"u" },   // o, oo, ou	lug, monkey, blood, double
  { "ə", "ah" },   // er, i, ar, our, ur	about, ladder, pencil, dollar, honour, augur
  { "ɛ", "eh" },   // er, i, ar, our, ur	about, ladder, pencil, dollar, honour, augur

  { "j",	"y" },    // i, j	you, onion, hallelujah	Yes
  { "dʒ", "j" },   // ge, g, dge, di, gg	jam, wage, giraffe, edge, soldier, exaggerate	Yesi
  { "ʒ",	"zh" },    // si, z	treasure, division, azure	Yes
  { "tʃ", "tsh" }, // tch, tu, ti, te	chip, watch, future, action, righteous	No
  { "ʃ",	"sh" },   // ce, s, ci, si, ch, sci, ti	sham, ocean, sure, special, pension, machine, conscience, station	No
  { "θ",	"th" },   //	thongs	No
  { "ð",	"dh" },   //	leather	Yes
  { "ŋ",	"ng" },   // n, ngue	ring, pink, tongue	Yes
  { "b",	"b" },    //	bug, bubble
  { "d",	"d" },    // dd, ed	dad, add, milled	Yes
  { "f",	"f" },    // ff, ph, gh, lf, ft	fat, cliff, phone, enough, half, often	No
  { "g",	"g" },    // gg, gh,gu,gue	gun, egg, ghost, guest, prologue	Yes
  { "h",	"h" },    // wh	hop, who	No
  { "k",	"k" },    // c, ch, cc, lk, qu ,q(u), ck, x	kit, cat, chris, accent, folk, bouquet, queen, rack, box	No
  { "l",	"l" },    // ll	live, well	Yes
  { "m",	"m" },    // mm, mb, mn, lm	man, summer, comb, column, palm	Yes
  { "n",	"n" },    // nn,kn, gn, pn, mn	net, funny, know, gnat, pneumonic, mneumonic	Yes
  { "p",	"p" },    // pp	pin, dippy	No
  { "r",	"r" },    // rr, wr, rh	run, carrot, wrench, rhyme	Yes
  { "s",	"s" },    // ss, c, sc, ps, st, ce, se	sit, less, circle, scene, psycho, listen, pace, course	No
  { "t",	"t" },    // tt, th, ed	tip, matter, thomas, ripped	No
  { "v",	"v" },    // f, ph, ve	vine, of, stephen, five	Yes
  { "w",	"w" },    // wh, u, o	wit, why, quick, choir	Yes
  { "z",	"z" },    // zz, s, ss, x, ze, se	zed, buzz, his, scissors, xylophone, craze	Yes
};
std::string getButterSpelling(const std::string& phonetics) {
  std::string butterSpelling = phonetics;
  for (std::pair<std::string, std::string> dictionaryEntry : butterDictionary)
    findAndReplaceAll(butterSpelling, dictionaryEntry.first, dictionaryEntry.second);
  return butterSpelling;
}

#include "../potions/unchoco.hpp"
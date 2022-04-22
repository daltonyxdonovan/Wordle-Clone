#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::find;



const float spacing = { 5.2 };
std::int16_t input1[2] = { -32,-600 };
std::int16_t input2[2] = { -50,-600 };
std::int16_t input3[2] = { -60,-600 };
std::int16_t input4[2] = { -70,-600 };
std::int16_t input5[2] = { -80,-600 };
std::int16_t past_guess_one_first[2] = { -34, -2 };
std::int16_t past_guess_one_second[2] = { -37, -2 };
std::int16_t past_guess_one_third[2] = { -42, -2 };
std::int16_t past_guess_one_fourth[2] = { -47, -2 };
std::int16_t past_guess_one_fifth[2] = { -50, -2 };
std::int16_t past_guess_two_first[2] = { -34, -97 };
std::int16_t past_guess_two_second[2] = { -38, -97 };
std::int16_t past_guess_two_third[2] = { -46, -97 };
std::int16_t past_guess_two_fourth[2] = { -54, -97 };
std::int16_t past_guess_two_fifth[2] = { -62, -97 };
std::int16_t past_guess_three_first[2] = { -34, -190 };
std::int16_t past_guess_three_second[2] = { -38, -190 };
std::int16_t past_guess_three_third[2] = { -46, -190 };
std::int16_t past_guess_three_fourth[2] = { -54, -190 };
std::int16_t past_guess_three_fifth[2] = { -62, -190 };
std::int16_t past_guess_four_first[2] = { -34, -292 };
std::int16_t past_guess_four_second[2] = { -38, -292 };
std::int16_t past_guess_four_third[2] = { -46, -292 };
std::int16_t past_guess_four_fourth[2] = { -54, -292 };
std::int16_t past_guess_four_fifth[2] = { -62, -292 };
std::int16_t past_guess_five_first[2] = { -34, -386 };
std::int16_t past_guess_five_second[2] = { -38, -386 };
std::int16_t past_guess_five_third[2] = { -46, -386 };
std::int16_t past_guess_five_fourth[2] = { -54, -386 };
std::int16_t past_guess_five_fifth[2] = { -62, -386 };
std::int16_t past_guess_six_first[2] = { -34, -482 };
std::int16_t past_guess_six_second[2] = { -38, -482 };
std::int16_t past_guess_six_third[2] = { -46, -482 };
std::int16_t past_guess_six_fourth[2] = { -54, -482 };
std::int16_t past_guess_six_fifth[2] = { -62, -482 };
int enterflag{ 0 };
std::string guess_full[5] = {};
std::string past_guess1[5] = {};
std::string past_guess2[5] = {};
std::string past_guess3[5] = {};
std::string past_guess4[5] = {};
std::string past_guess5[5] = {};
std::string past_guess6[5] = {};
std::string box_rects[60] = {};
std::string guess[5] = {};
std::string words_list[577] = { "Adult", "Agent", "Anger", "Apple", "Award", "Basis", "Beach", "Birth", "Block", "Blood", "Board", "Brain", "Bread", "Break", "Brown", "Buyer", "Cause", "Chain", "Chair", "Chest", "Chief", "Child", "China", "Claim", "Class", "Clock", "Coach", "Coast", "Court", "Cover", "Cream", "Crime", "Cross", "Crowd", "Crown", "Cycle", "Dance", "Depth", "Doubt", "Draft", "Drama", "Dream", "Dress", "Drink", "Drive", "Earth", "Enemy", "Entry", "Error", "Event", "Faith", "Fault", "Field", "Fight", "Final", "Floor", "Focus", "Force", "Frame", "Frank", "Front", "Fruit", "Glass", "Grant", "Grass", "Green", "Group", "Guide", "Heart", "Horse", "Hotel", "House", "Image", "Index", "Input", "Issue", "Judge", "Knife", "Layer", "Level", "Light", "Limit", "Lunch", "Major", "March", "Match", "Metal", "Model", "Money", "Month", "Motor", "Mouth", "Music", "Night", "Noise", "North", "Novel", "Nurse", "Offer", "Order", "Other", "Owner", "Panel", "Paper", "Party", "Peace", "Peter", "Phase", "Phone", "Piece", "Pilot", "Pitch", "Place", "Plane", "Plant", "Plate", "Point", "Pound", "Power", "Press", "Price", "Pride", "Prize", "Proof", "Queen", "Radio", "Range", "Ratio", "Reply", "Right", "River", "Round", "Route", "Rugby", "Scale", "Scene", "Scope", "Score", "Sense", "Shape", "Share", "Sheep", "Sheet", "Shift", "Shirt", "Shock", "Sight", "Simon", "Skill", "Sleep", "Smile", "Smith", "Smoke", "Sound", "South", "Space", "Speed", "Spite", "Sport", "Squad", "Staff", "Stage", "Start", "State", "Steam", "Steel", "Stock", "Stone", "Store", "Study", "Stuff", "Style", "Sugar", "Table", "Taste", "Theme", "Thing", "Title", "Total", "Touch", "Tower", "Track", "Trade", "Train", "Trend", "Trial", "Trust", "Truth", "Uncle", "Union", "Unity", "Value", "Video", "Visit", "Voice", "Waste", "Watch", "Water", "While", "White", "Whole", "Woman", "World", "Youth", "Admit", "Adopt", "Agree", "Allow", "Alter", "Apply", "Argue", "Arise", "Avoid", "Begin", "Blame", "Break", "Bring", "Build", "Burst", "Carry", "Catch", "Cause", "Check", "Claim", "Clean", "Clear", "Climb", "Close", "Count", "Cover", "Cross", "Dance", "Doubt", "Drink", "Drive", "Enjoy", "Enter", "Exist", "Fight", "Focus", "Force", "Guess", "Imply", "Issue", "Judge", "Laugh", "Learn", "Leave", "Limit", "Marry", "Match", "Occur", "Offer", "Order", "Phone", "Place", "Point", "Press", "Prove", "Raise", "Reach", "Refer", "Relax", "Serve", "Shall", "Share", "Shift", "Shoot", "Sleep", "Solve", "Sound", "Speak", "Spend", "Split", "Stand", "Start", "State", "Stick", "Study", "Teach", "Thank", "Think", "Throw", "Touch", "Train", "Treat", "Trust", "Visit", "Voice", "Waste", "Watch", "Worry", "Would", "Write", "Above", "Acute", "Alive", "Alone", "Angry", "Aware", "Awful", "Basic", "Black", "Blind", "Brave", "Brief", "Broad", "Brown", "Cheap", "Chief", "Civil", "Clean", "Clear", "Close", "Crazy", "Daily", "Dirty", "Early", "Empty", "Equal", "Exact", "Extra", "Faint", "False", "Fifth", "Final", "First", "Fresh", "Front", "Funny", "Giant", "Grand", "Great", "Green", "Gross", "Happy", "Harsh", "Heavy", "Human", "Ideal", "Inner", "Joint", "Large", "Legal", "Level", "Light", "Local", "Loose", "Lucky", "Magic", "Major", "Minor", "Moral", "Naked", "Nasty", "Naval", "Other", "Outer", "Plain", "Prime", "Prior", "Proud", "Quick", "Quiet", "Rapid", "Ready", "Right", "Roman", "Rough", "Round", "Royal", "Rural", "Sharp", "Sheer", "Short", "Silly", "Sixth", "Small", "Smart", "Solid", "Sorry", "Spare", "Steep", "Still", "Super", "Sweet", "Thick", "Third", "Tight", "Total", "Tough", "Upper", "Upset", "Urban", "Usual", "Vague", "Valid", "Vital", "White", "Whole", "Wrong", "Young", "Afore", "After", "Bothe", "Other", "Since", "Slash", "Until", "Where", "While", "Aback", "Abaft", "Aboon", "About", "Above", "Accel", "Adown", "Afoot", "Afore", "Afoul", "After", "Again", "Agape", "Agogo", "Agone", "Ahead", "Ahull", "Alife", "Alike", "Aline", "Aloft", "Alone", "Along", "Aloof", "Aloud", "Amiss", "Amply", "Amuck", "Apace", "Apart", "Aptly", "Arear", "Aside", "Askew", "Awful", "Badly", "Bally", "Below", "Canny", "Cheap", "Clean", "Clear", "Coyly", "Daily", "Dimly", "Dirty", "Ditto", "Drily", "Dryly", "Dully", "Early", "Extra", "False", "Fatly", "Feyly", "First", "Fitly", "Forte", "Forth", "Fresh", "Fully", "Funny", "Gaily", "Gayly", "Godly", "Great", "Haply", "Heavy", "Hella", "Hence", "Hotly", "Icily", "Infra", "Intl.", "Jildi", "Jolly", "Laxly", "Lento", "Light", "Lowly", "Madly", "Maybe", "Never", "Newly", "Nobly", "Oddly", "Often", "Other", "Ought", "Party", "Piano", "Plain", "Plonk", "Plumb", "Prior", "Queer", "Quick", "Quite", "Ramen", "Rapid", "Redly", "Right", "Rough", "Round", "Sadly", "Secus", "Selly", "Sharp", "Sheer", "Shily", "Short", "Shyly", "Silly", "Since", "Sleek", "Slyly", "Small", "Sound", "Spang", "Stark", "Still", "Stone", "Stour", "Super", "Tally", "Tanto", "There", "Thick", "Tight", "Today", "Tomoz", "Truly", "Twice", "Under", "Utter", "Verry", "Wanly", "Wetly", "Where", "Wrong", "Wryly", "Abaft", "Aboon", "About", "Above", "Adown", "Afore", "After", "Along", "Aloof", "Among", "Below", "Circa", "Cross", "Furth", "Minus", "Neath", "Round", "Since", "Spite", "Under", "Until" };
vector<string> dictionary_list = { "adult", "agent", "anger", "apple", "award", "basis", "beach", "birth", "block", "blood", "board", "brain", "bread", "break", "brown", "buyer", "cause", "chain", "chair", "chest", "chief", "child", "china", "claim", "class", "clock", "coach", "coast", "court", "cover", "cream", "crime", "cross", "crowd", "crown", "cycle", "dance", "depth", "doubt", "draft", "drama", "dream", "dress", "drink", "drive", "earth", "enemy", "entry", "error", "event", "faith", "fault", "field", "fight", "final", "floor", "focus", "force", "frame", "frank", "front", "fruit", "glass", "grant", "grass", "green", "group", "guide", "heart", "horse", "hotel", "house", "image", "index", "input", "issue", "judge", "knife", "layer", "level", "light", "limit", "lunch", "major", "march", "match", "metal", "model", "money", "month", "motor", "mouth", "music", "night", "noise", "north", "novel", "nurse", "offer", "order", "other", "owner", "panel", "paper", "party", "peace", "peter", "phase", "phone", "piece", "pilot", "pitch", "place", "plane", "plant", "plate", "point", "pound", "power", "press", "price", "pride", "prize", "proof", "queen", "radio", "range", "ratio", "reply", "right", "river", "round", "route", "rugby", "scale", "scene", "scope", "score", "sense", "shape", "share", "sheep", "sheet", "shift", "shirt", "shock", "sight", "simon", "skill", "sleep", "smile", "smith", "smoke", "sound", "south", "space", "speed", "spite", "sport", "squad", "staff", "stage", "start", "state", "steam", "steel", "stock", "stone", "store", "study", "stuff", "style", "sugar", "table", "taste", "theme", "thing", "title", "total", "touch", "tower", "track", "trade", "train", "trend", "trial", "trust", "truth", "uncle", "union", "unity", "value", "video", "visit", "voice", "waste", "watch", "water", "while", "white", "whole", "woman", "world", "youth", "admit", "adopt", "agree", "allow", "alter", "apply", "argue", "arise", "avoid", "begin", "blame", "break", "bring", "build", "burst", "carry", "catch", "cause", "check", "claim", "clean", "clear", "climb", "close", "count", "cover", "cross", "dance", "doubt", "drink", "drive", "enjoy", "enter", "exist", "fight", "focus", "force", "guess", "imply", "issue", "judge", "laugh", "learn", "leave", "limit", "marry", "match", "occur", "offer", "order", "phone", "place", "point", "press", "prove", "raise", "reach", "refer", "relax", "serve", "shall", "share", "shift", "shoot", "sleep", "solve", "sound", "speak", "spend", "split", "stand", "start", "state", "stick", "study", "teach", "thank", "think", "throw", "touch", "train", "treat", "trust", "visit", "voice", "waste", "watch", "worry", "would", "write", "above", "acute", "alive", "alone", "angry", "aware", "awful", "basic", "black", "blind", "brave", "brief", "broad", "brown", "cheap", "chief", "civil", "clean", "clear", "close", "crazy", "daily", "dirty", "early", "empty", "equal", "exact", "extra", "faint", "false", "fifth", "final", "first", "fresh", "front", "funny", "giant", "grand", "great", "green", "gross", "happy", "harsh", "heavy", "human", "ideal", "inner", "joint", "large", "legal", "level", "light", "local", "loose", "lucky", "magic", "major", "minor", "moral", "naked", "nasty", "naval", "other", "outer", "plain", "prime", "prior", "proud", "quick", "quiet", "rapid", "ready", "right", "roman", "rough", "round", "royal", "rural", "sharp", "sheer", "short", "silly", "sixth", "small", "smart", "solid", "sorry", "spare", "steep", "still", "super", "sweet", "thick", "third", "tight", "total", "tough", "upper", "upset", "urban", "usual", "vague", "valid", "vital", "white", "whole", "wrong", "young", "afore", "after", "bothe", "other", "since", "slash", "until", "where", "while", "aback", "abaft", "aboon", "about", "above", "accel", "adown", "afoot", "afore", "afoul", "after", "again", "agape", "agogo", "agone", "ahead", "ahull", "alife", "alike", "aline", "aloft", "alone", "along", "aloof", "aloud", "amiss", "amply", "amuck", "apace", "apart", "aptly", "arear", "aside", "askew", "awful", "badly", "bally", "below", "canny", "cheap", "clean", "clear", "coyly", "daily", "dimly", "dirty", "ditto", "drily", "dryly", "dully", "early", "extra", "false", "fatly", "feyly", "first", "fitly", "forte", "forth", "fresh", "fully", "funny", "gaily", "gayly", "godly", "great", "haply", "heavy", "hella", "hence", "hotly", "icily", "infra", "intl.", "jildi", "jolly", "laxly", "lento", "light", "lowly", "madly", "maybe", "never", "newly", "nobly", "oddly", "often", "other", "ought", "party", "piano", "plain", "plonk", "plumb", "prior", "queer", "quick", "quite", "ramen", "rapid", "redly", "right", "rough", "round", "sadly", "secus", "selly", "sharp", "sheer", "shily", "short", "shyly", "silly", "since", "sleek", "slyly", "small", "sound", "spang", "stark", "still", "stone", "stour", "super", "tally", "tanto", "there", "thick", "tight", "today", "tomoz", "truly", "twice", "under", "utter", "verry", "wanly", "wetly", "where", "wrong", "wryly", "abaft", "aboon", "about", "above", "adown", "afore", "after", "along", "aloof", "among", "below", "circa", "cross", "furth", "minus", "neath", "round", "since", "spite", "under", "until",
"which", "there", "their", "about", "would", "these", "other", "words", "could", "write", "first", "water", "after", "where", "right", "think", "three", "years", "place", "sound", "great", "again", "still",
"every", "small", "found", "those", "never", "under", "might", "while", "house", "world", "below", "asked", "going", "large", "until", "along", "shall", "being", "often", "earth", "began", "since", "study",
"night", "light", "above", "paper", "parts", "young", "story", "point", "times", "heard", "whole", "white", "given", "means", "music", "miles", "thing", "today", "later", "using", "money", "lines", "order",
"group", "among", "learn", "known", "space", "table", "early", "trees", "short", "hands", "state", "black", "shown", "stood", "front", "voice", "kinds", "makes", "comes", "close", "power", "lived", "vowel",
"taken", "built", "heart", "ready", "quite", "class", "bring", "round", "horse", "shows", "piece", "green", "stand", "birds", "start", "river", "tried", "least", "field", "whose", "girls", "leave", "added",
"color", "third", "hours", "moved", "plant", "doing", "names", "forms", "heavy", "ideas", "cried", "check", "floor", "begin", "woman", "alone", "plane", "spell", "watch", "carry", "wrote", "clear", "named",
"books", "child", "glass", "human", "takes", "party", "build", "seems", "blood", "sides", "seven", "mouth", "solve", "north", "value", "death", "maybe", "happy", "tells", "gives", "looks", "shape", "lives",
"steps", "areas", "sense", "speak", "force", "ocean", "speed", "women", "metal", "south", "grass", "scale", "cells", "lower", "sleep", "wrong", "pages", "ships", "needs", "rocks", "eight", "major", "level",
"total", "ahead", "reach", "stars", "store", "sight", "terms", "catch", "works", "board", "cover", "songs", "equal", "stone", "waves", "guess", "dance", "spoke", "break", "cause", "radio", "weeks", "lands",
"basic", "liked", "trade", "fresh", "final", "fight", "meant", "drive", "spent", "local", "waxes", "knows", "train", "bread", "homes", "teeth", "coast", "thick", "brown", "clean", "quiet", "sugar", "facts",
"steel", "forth", "rules", "notes", "units", "peace", "month", "verbs", "seeds", "helps", "sharp", "visit", "woods", "chief", "walls", "cross", "wings", "grown", "cases", "foods", "crops", "fruit", "stick",
"wants", "stage", "sheep", "nouns", "plain", "drink", "bones", "apart", "turns", "moves", "touch", "angle", "based", "range", "marks", "tired", "older", "farms", "spend", "shoes", "goods", "chair", "twice",
"cents", "empty", "alike", "style", "broke", "pairs", "count", "enjoy", "score", "shore", "roots", "paint", "heads", "shook", "serve", "angry", "crowd", "wheel", "quick", "dress", "share", "alive", "noise",
"solid", "cloth", "signs", "hills", "types", "drawn", "worth", "truck", "piano", "upper", "loved", "usual", "faces", "drove", "cabin", "boats", "towns", "proud", "court", "model", "prime", "fifty", "plans",
"yards", "prove", "tools", "price", "sheet", "smell", "boxes", "raise", "match", "truth", "roads", "threw", "enemy", "lunch", "chart", "scene", "graph", "doubt", "guide", "winds", "block", "grain", "smoke",
"mixed", "games", "wagon", "sweet", "topic", "extra", "plate", "title", "knife", "fence", "falls", "cloud", "wheat", "plays", "enter", "broad", "steam", "atoms", "press", "lying", "basis", "clock", "taste",
"grows", "thank", "storm", "agree", "brain", "track", "smile", "funny", "beach", "stock", "hurry", "saved", "sorry", "giant", "trail", "offer", "ought", "rough", "daily", "avoid", "keeps", "throw", "allow",
"cream", "laugh", "edges", "teach", "frame", "bells", "dream", "magic", "occur", "ended", "chord", "false", "skill", "holes", "dozen", "brave", "apple", "climb", "outer", "pitch", "ruler", "holds", "fixed",
"costs", "calls", "blank", "staff", "labor", "eaten", "youth", "tones", "honor", "globe", "gases", "doors", "poles", "loose", "apply", "tears", "exact", "brush", "chest", "layer", "whale", "minor", "faith",
"tests", "judge", "items", "worry", "waste", "hoped", "strip", "begun", "aside", "lakes", "bound", "depth", "candy", "event", "worse", "aware", "shell", "rooms", "ranch", "image", "snake", "aloud", "dried",
"likes", "motor", "pound", "knees", "refer", "fully", "chain", "shirt", "flour", "drops", "spite", "orbit", "banks", "shoot", "curve", "tribe", "tight", "blind", "slept", "shade", "claim", "flies", "theme",
"queen", "fifth", "union", "hence", "straw", "entry", "issue", "birth", "feels", "anger", "brief", "rhyme", "glory", "guard", "flows", "flesh", "owned", "trick", "yours", "sizes", "noted", "width", "burst",
"route", "lungs", "uncle", "bears", "royal", "kings", "forty", "trial", "cards", "brass", "opera", "chose", "owner", "vapor", "beats", "mouse", "tough", "wires", "meter", "tower", "finds", "inner", "stuck",
"arrow", "poems", "label", "swing", "solar", "truly", "tense", "beans", "split", "rises", "weigh", "hotel", "stems", "pride", "swung", "grade", "digit", "badly", "boots", "pilot", "sales", "swept", "lucky",
"prize", "stove", "tubes", "acres", "wound", "steep", "slide", "trunk", "error", "porch", "slave", "exist", "faced", "mines", "marry", "juice", "raced", "waved", "goose", "trust", "fewer", "favor", "mills",
"views", "joint", "eager", "spots", "blend", "rings", "adult", "index", "nails", "horns", "balls", "flame", "rates", "drill", "trace", "skins", "waxed", "seats", "stuff", "ratio", "minds", "dirty", "silly",
"coins", "hello", "trips", "leads", "rifle", "hopes", "bases", "shine", "bench", "moral", "fires", "meals", "shake", "shops", "cycle", "movie", "slope", "canoe", "teams", "folks", "fired", "bands", "thumb",
"shout", "canal", "habit", "reply", "ruled", "fever", "crust", "shelf", "walks", "midst", "crack", "print", "tales", "coach", "stiff", "flood", "verse", "awake", "rocky", "march", "fault", "swift", "faint",
"civil", "ghost", "feast", "blade", "limit", "germs", "reads", "ducks", "dairy", "worst", "gifts", "lists", "stops", "rapid", "brick", "claws", "beads", "beast", "skirt", "cakes", "lions", "frogs", "tries",
"nerve", "grand", "armed", "treat", "honey", "moist", "legal", "penny", "crown", "shock", "taxes", "sixty", "altar", "pulls", "sport", "drums", "talks", "dying", "dates", "drank", "blows", "lever", "wages",
"proof", "drugs", "tanks", "sings", "tails", "pause", "herds", "arose", "hated", "clues", "novel", "shame", "burnt", "races", "flash", "weary", "heels", "token", "coats", "spare", "shiny", "alarm", "dimes",
"sixth", "clerk", "mercy", "sunny", "guest", "float", "shone", "pipes", "worms", "bills", "sweat", "suits", "smart", "upset", "rains", "sandy", "rainy", "parks", "sadly", "fancy", "rider", "unity", "bunch",
"rolls", "crash", "craft", "newly", "gates", "hatch", "paths", "funds", "wider", "grace", "grave", "tides", "admit", "shift", "sails", "pupil", "tiger", "angel", "cruel", "agent", "drama", "urged", "patch",
"nests", "vital", "sword", "blame", "weeds", "screw", "vocal", "bacon", "chalk", "cargo", "crazy", "acted", "goats", "arise", "witch", "loves", "queer", "dwell", "backs", "ropes", "shots", "merry", "phone",
"cheek", "peaks", "ideal", "beard", "eagle", "creek", "cries", "ashes", "stall", "yield", "mayor", "opens", "input", "fleet", "tooth", "cubic", "wives", "burns", "poets", "apron", "spear", "organ", "cliff",
"stamp", "paste", "rural", "baked", "chase", "slice", "slant", "knock", "noisy", "sorts", "stays", "wiped", "blown", "piled", "clubs", "cheer", "widow", "twist", "tenth", "hides", "comma", "sweep", "spoon",
"stern", "crept", "maple", "deeds", "rides", "muddy", "crime", "jelly", "ridge", "drift", "dusty", "devil", "tempo", "humor", "sends", "steal", "tents", "waist", "roses", "reign", "noble", "cheap", "dense",
"linen", "geese", "woven", "posts", "hired", "wrath", "salad", "bowed", "tires", "shark", "belts", "grasp", "blast", "polar", "fungi", "tends", "pearl", "loads", "jokes", "veins", "frost", "hears", "loses",
"hosts", "diver", "phase", "toads", "alert", "tasks", "seams", "coral", "focus", "naked", "puppy", "jumps", "spoil", "quart", "macro", "fears", "flung", "spark", "vivid", "brook", "steer", "spray", "decay",
"ports", "socks", "urban", "goals", "grant", "minus", "films", "tunes", "shaft", "firms", "skies", "bride", "wreck", "flock", "stare", "hobby", "bonds", "dared", "faded", "thief", "crude", "pants", "flute",
"votes", "tonal", "radar", "wells", "skull", "hairs", "argue", "wears", "dolls", "voted", "caves", "cared", "broom", "scent", "panel", "fairy", "olive", "bends", "prism", "lamps", "cable", "peach", "ruins",
"rally", "schwa", "lambs", "sells", "cools", "draft", "charm", "limbs", "brake", "gazed", "cubes", "delay", "beams", "fetch", "ranks", "array", "harsh", "camel", "vines", "picks", "naval", "purse", "rigid",
"crawl", "toast", "soils", "sauce", "basin", "ponds", "twins", "wrist", "fluid", "pools", "brand", "stalk", "robot", "reeds", "hoofs", "buses", "sheer", "grief", "bloom", "dwelt", "melts", "risen", "flags",
"knelt", "fiber", "roofs", "freed", "armor", "piles", "aimed", "algae", "twigs", "lemon", "ditch", "drunk", "rests", "chill", "slain", "panic", "cords", "tuned", "crisp", "ledge", "dived", "swamp", "clung",
"stole", "molds", "yarns", "liver", "gauge", "breed", "stool", "gulls", "awoke", "gross", "diary", "rails", "belly", "trend", "flask", "stake", "fried", "draws", "actor", "handy", "bowls", "haste", "scope",
"deals", "knots", "moons", "essay", "thump", "hangs", "bliss", "dealt", "gains", "bombs", "clown", "palms", "cones", "roast", "tidal", "bored", "chant", "acids", "dough", "camps", "swore", "lover", "hooks",
"males", "cocoa", "punch", "award", "reins", "ninth", "noses", "links", "drain", "fills", "nylon", "lunar", "pulse", "flown", "elbow", "fatal", "sites", "moths", "meats", "foxes", "mined", "attic", "fiery",
"mount", "usage", "swear", "snowy", "rusty", "scare", "traps", "relax", "react", "valid", "robin", "cease", "gills", "prior", "safer", "polio", "loyal", "swell", "salty", "marsh", "vague", "weave", "mound",
"seals", "mules", "virus", "scout", "acute", "windy", "stout", "folds", "seize", "hilly", "joins", "pluck", "stack", "lords", "dunes", "burro", "hawks", "trout", "feeds", "scarf", "halls", "coals", "towel",
"souls", "elect", "buggy", "pumps", "loans", "spins", "files", "oxide", "pains", "photo", "rival", "flats", "syrup", "rodeo", "sands", "moose", "pints", "curly", "comic", "cloak", "onion", "clams", "scrap",
"didst", "couch", "codes", "fails", "ounce", "lodge", "greet", "gypsy", "utter", "paved", "zones", "fours", "alley", "tiles", "bless", "crest", "elder", "kills", "yeast", "erect", "bugle", "medal", "roles",
"hound", "snail", "alter", "ankle", "relay", "loops", "zeros", "bites", "modes", "debts", "realm", "glove", "rayon", "swims", "poked", "stray", "lifts", "maker", "lumps", "graze", "dread", "barns", "docks",
"masts", "pours", "wharf", "curse", "plump", "robes", "seeks", "cedar", "curls", "jolly", "myths", "cages", "gloom", "locks", "pedal", "beets", "crows", "anode", "slash", "creep", "rowed", "chips", "fists",
"wines", "cares", "valve", "newer", "motel", "ivory", "necks", "clamp", "barge", "blues", "alien", "frown", "strap", "crews", "shack", "gonna", "saves", "stump", "ferry", "idols", "cooks", "juicy", "glare",
"carts", "alloy", "bulbs", "lawns", "lasts", "fuels", "oddly", "crane", "filed", "weird", "shawl", "slips", "troop", "bolts", "suite", "sleek", "quilt", "tramp", "blaze", "atlas", "odors", "scrub", "crabs",
"probe", "logic", "adobe", "exile", "rebel", "grind", "sting", "spine", "cling", "desks", "grove", "leaps", "prose", "lofty", "agony", "snare", "tusks", "bulls", "moods", "humid", "finer", "dimly", "plank",
"china", "pines", "guilt", "sacks", "brace", "quote", "lathe", "gaily", "fonts", "scalp", "adopt", "foggy", "ferns", "grams", "clump", "perch", "tumor", "teens", "crank", "fable", "hedge", "genes", "sober",
"boast", "tract", "cigar", "unite", "owing", "thigh", "haiku", "swish", "dikes", "wedge", "booth", "eased", "frail", "cough", "tombs", "darts", "forts", "choir", "pouch", "pinch", "hairy", "buyer", "torch",
"vigor", "waltz", "heats", "herbs", "users", "flint", "click", "madam", "bleak", "blunt", "aided", "lacks", "masks", "waded", "risks", "nurse", "chaos", "sewed", "cured", "ample", "lease", "steak", "sinks",
"merit", "bluff", "bathe", "gleam", "bonus", "colts", "shear", "gland", "silky", "skate", "birch", "anvil", "sleds", "groan", "maids", "meets", "speck", "hymns", "hints", "drown", "bosom", "slick", "quest",
"coils", "spied", "snows", "stead", "snack", "plows", "blond", "tamed", "thorn", "waits", "glued", "banjo", "tease", "arena", "bulky", "carve", "stunt", "warms", "shady", "razor", "folly", "leafy", "notch",
"fools", "otter", "pears", "flush", "genus", "ached", "fives", "flaps", "spout", "smote", "fumes", "adapt", "cuffs", "tasty", "stoop", "clips", "disks", "sniff", "lanes", "brisk", "imply", "demon", "super",
"furry", "raged", "growl", "texts", "hardy", "stung", "typed", "hates", "wiser", "timid", "serum", "beaks", "rotor", "casts", "baths", "glide", "plots", "trait", "resin", "slums", "lyric", "puffs", "decks",
"brood", "mourn", "aloft", "abuse", "whirl", "edged", "ovary", "quack", "heaps", "slang", "await", "civic", "saint", "bevel", "sonar", "aunts", "packs", "froze", "tonic", "corps", "swarm", "frank", "repay",
"gaunt", "wired", "niece", "cello", "needy", "chuck", "stony", "media", "surge", "hurts", "repel", "husky", "dated", "hunts", "mists", "exert", "dries", "mates", "sworn", "baker", "spice", "oasis", "boils",
"spurs", "doves", "sneak", "paces", "colon", "siege", "strum", "drier", "cacao", "humus", "bales", "piped", "nasty", "rinse", "boxer", "shrub", "amuse", "tacks", "cited", "slung", "delta", "laden", "larva",
"rents", "yells", "spool", "spill", "crush", "jewel", "snaps", "stain", "kicks", "tying", "slits", "rated", "eerie", "smash", "plums", "zebra", "earns", "bushy", "scary", "squad", "tutor", "silks", "slabs",
"bumps", "evils", "fangs", "snout", "peril", "pivot", "yacht", "lobby", "jeans", "grins", "viola", "liner", "comet", "scars", "chops", "raids", "eater", "slate", "skips", "soles", "misty", "urine", "knobs",
"sleet", "holly", "pests", "forks", "grill", "trays", "pails", "borne", "tenor", "wares", "carol", "woody", "canon", "wakes", "kitty", "miner", "polls", "shaky", "nasal", "scorn", "chess", "taxis", "crate",
"shyly", "tulip", "forge", "nymph", "budge", "lowly", "abide", "depot", "oases", "asses", "sheds", "fudge", "pills", "rivet", "thine", "groom", "lanky", "boost", "broth", "heave", "gravy", "beech", "timed",
"quail", "inert", "gears", "chick", "hinge", "trash", "clash", "sighs", "renew", "bough", "dwarf", "slows", "quill", "shave", "spore", "sixes", "chunk", "madly", "paced", "braid", "fuzzy", "motto", "spies",
"slack", "mucus", "magma", "awful", "discs", "erase", "posed", "asset", "cider", "taper", "theft", "churn", "satin", "slots", "taxed", "bully", "sloth", "shale", "tread", "raked", "curds", "manor", "aisle",
"bulge", "loins", "stair", "tapes", "leans", "bunks", "squat", "towed", "lance", "panes", "sakes", "heirs", "caste", "dummy", "pores", "fauna", "crook", "poise", "epoch", "risky", "warns", "fling", "berry",
"grape", "flank", "drags", "squid", "pelts", "icing", "irony", "irons", "barks", "whoop", "choke", "diets", "whips", "tally", "dozed", "twine", "kites", "bikes", "ticks", "riots", "roars", "vault", "looms",
"scold", "blink", "dandy", "pupae", "sieve", "spike", "ducts", "lends", "pizza", "brink", "widen", "plumb", "pagan", "feats", "bison", "soggy", "scoop", "argon", "nudge", "skiff", "amber", "sexes", "rouse",
"salts", "hitch", "exalt", "leash", "dined", "chute", "snort", "gusts", "melon", "cheat", "reefs", "llama", "lasso", "debut", "quota", "oaths", "prone", "mixes", "rafts", "dives", "stale", "inlet", "flick",
"pinto", "brows", "untie", "batch", "greed", "chore", "stirs", "blush", "onset", "barbs", "volts", "beige", "swoop", "paddy", "laced", "shove", "jerky", "poppy", "leaks", "fares", "dodge", "godly", "squaw",
"affix", "brute", "nicer", "undue", "snarl", "merge", "doses", "showy", "daddy", "roost", "vases", "swirl", "petty", "colds", "curry", "cobra", "genie", "flare", "messy", "cores", "soaks", "ripen", "whine",
"amino", "plaid", "spiny", "mowed", "baton", "peers", "vowed", "pious", "swans", "exits", "afoot", "plugs", "idiom", "chili", "rites", "serfs", "cleft", "berth", "grubs", "annex", "dizzy", "hasty", "latch",
"wasps", "mirth", "baron", "plead", "aloof", "aging", "pixel", "bared", "mummy", "hotly", "auger", "buddy", "chaps", "badge", "stark", "fairs", "gully", "mumps", "emery", "filly", "ovens", "drone", "gauze",
"idiot", "fussy", "annoy", "shank", "gouge", "bleed", "elves", "roped", "unfit", "baggy", "mower", "scant", "grabs", "fleas", "lousy", "album", "sawed", "cooky", "murky", "infer", "burly", "waged", "dingy",
"brine", "kneel", "creak", "vanes", "smoky", "spurt", "combs", "easel", "laces", "humps", "rumor", "aroma", "horde", "swiss", "leapt", "opium", "slime", "afire", "pansy", "mares", "soaps", "husks", "snips",
"hazel", "lined", "cafes", "naive", "wraps", "sized", "piers", "beset", "agile", "tongs", "steed", "fraud", "booty", "valor", "downy", "witty", "mossy", "psalm", "scuba", "tours", "polka", "milky", "gaudy",
"shrug", "tufts", "wilds", "laser", "truss", "hares", "creed", "lilac", "siren", "tarry", "bribe", "swine", "muted", "flips", "cures", "sinew", "boxed", "hoops", "gasps", "hoods", "niche", "yucca", "glows",
"sewer", "whack", "fuses", "gowns", "droop", "bucks", "pangs", "mails", "whisk", "haven", "clasp", "sling", "stint", "urges", "champ", "piety", "chirp", "pleat", "posse", "sunup", "menus", "howls", "quake",
"knack", "plaza", "fiend", "caked", "bangs", "erupt", "poker", "olden", "cramp", "voter", "poses", "manly", "slump", "fined", "grips", "gaped", "purge", "hiked", "maize", "fluff", "strut", "sloop", "prowl",
"roach", "cocks", "bland", "dials", "plume", "slaps", "soups", "dully", "wills", "foams", "solos", "skier", "eaves", "totem", "fused", "latex", "veils", "mused", "mains", "myrrh", "racks", "galls", "gnats",
"bouts", "sisal", "shuts", "hoses", "dryly", "hover", "gloss", "seeps", "denim", "putty", "guppy", "leaky", "dusky", "filth", "oboes", "spans", "fowls", "adorn", "glaze", "haunt", "dares", "obeys", "bakes",
"abyss", "smelt", "gangs", "aches", "trawl", "claps", "undid", "spicy", "hoist", "fades", "vicar", "acorn", "pussy", "gruff", "musty", "tarts", "snuff", "hunch", "truce", "tweed", "dryer", "loser", "sheaf",
"moles", "lapse", "tawny", "vexed", "autos", "wager", "domes", "sheen", "clang", "spade", "sowed", "broil", "slyly", "studs", "grunt", "donor", "slugs", "aspen", "homer", "croak", "tithe", "halts", "avert",
"havoc", "hogan", "glint", "ruddy", "jeeps", "flaky", "ladle", "taunt", "snore", "fines", "props", "prune", "pesos", "radii", "pokes", "tiled", "daisy", "heron", "villa", "farce", "binds", "cites", "fixes",
"jerks", "livid", "waked", "inked", "booms", "chews", "licks", "hyena", "scoff", "lusty", "sonic", "smith", "usher", "tucks", "vigil", "molts", "sects", "spars", "dumps", "scaly", "wisps", "sores", "mince",
"panda", "flier", "axles", "plied", "booby", "patio", "rabbi", "petal", "polyp", "tints", "grate", "troll", "tolls", "relic", "phony", "bleat", "flaws", "flake", "snags", "aptly", "drawl", "ulcer", "soapy",
"bossy", "monks", "crags", "caged", "twang", "diner", "taped", "cadet", "grids", "spawn", "guile", "noose", "mores", "girth", "slimy", "aides", "spasm", "burrs", "alibi", "lymph", "saucy", "muggy", "liter",
"joked", "goofy", "exams", "enact", "stork", "lured", "toxic", "omens", "nears", "covet", "wrung", "forum", "venom", "moody", "alder", "sassy", "flair", "guild", "prays", "wrens", "hauls", "stave", "tilts",
"pecks", "stomp", "gales", "tempt", "capes", "mesas", "omits", "tepee", "harry", "wring", "evoke", "limes", "cluck", "lunge", "highs", "canes", "giddy", "lithe", "verge", "khaki", "queue", "loath", "foyer",
"outdo", "fared", "deter", "crumb", "astir", "spire", "jumpy", "extol", "buoys", "stubs", "lucid", "thong", "afore", "whiff", "maxim", "hulls", "clogs", "slats", "jiffy", "arbor", "cinch", "igloo", "goody",
"gazes", "dowel", "calms", "bitch", "scowl", "gulps", "coded", "waver", "mason", "lobes", "ebony", "flail", "isles", "clods", "dazed", "adept", "oozed", "sedan", "clays", "warts", "ketch", "skunk", "manes",
"adore", "sneer", "mango", "fiord", "flora", "roomy", "minks", "thaws", "watts", "freer", "exult", "plush", "paled", "twain", "clink", "scamp", "pawed", "grope", "bravo", "gable", "stink", "sever", "waned",
"rarer", "regal", "wards", "fawns", "babes", "unify", "amend", "oaken", "glade", "visor", "hefty", "nines", "throb", "pecan", "butts", "pence", "sills", "jails", "flyer", "saber", "nomad", "miter", "beeps",
"domed", "gulfs", "curbs", "heath", "moors", "aorta", "larks", "tangy", "wryly", "cheep", "rages", "evade", "lures", "freak", "vogue", "tunic", "slams", "knits", "dumpy", "mania", "spits", "firth", "hikes",
"trots", "nosed", "clank", "dogma", "bloat", "balsa", "graft", "middy", "stile", "keyed", "finch", "sperm", "chaff", "wiles", "amigo", "copra", "amiss", "eying", "twirl", "lurch", "popes", "chins", "smock",
"tines", "guise", "grits", "junks", "shoal", "cache", "tapir", "atoll", "deity", "toils", "spree", "mocks", "scans", "shorn", "revel", "raven", "hoary", "reels", "scuff", "mimic", "weedy", "corny", "truer",
"rouge", "ember", "floes", "torso", "wipes", "edict", "sulky", "recur", "groin", "baste", "kinks", "surer", "piggy", "moldy", "franc", "liars", "inept", "gusty", "facet", "jetty", "equip", "leper", "slink",
"soars", "cater", "dowry", "sided", "yearn", "decoy", "taboo", "ovals", "heals", "pleas", "beret", "spilt", "gayly", "rover", "endow", "pygmy", "carat", "abbey", "vents", "waken", "chimp", "fumed", "sodas",
"vinyl", "clout", "wades", "mites", "smirk", "bores", "bunny", "surly", "frock", "foray", "purer", "milks", "query", "mired", "blare", "froth", "gruel", "navel", "paler", "puffy", "casks", "grime", "derby",
"mamma", "gavel", "teddy", "vomit", "moans", "allot", "defer", "wield", "viper", "louse", "erred", "hewed", "abhor", "wrest", "waxen", "adage", "ardor", "stabs", "pored", "rondo", "loped", "fishy", "bible",
"hires", "foals", "feuds", "jambs", "thuds", "jeers", "knead", "quirk", "rugby", "expel", "greys", "rigor", "ester", "lyres", "aback", "glues", "lotus", "lurid", "rungs", "hutch", "thyme", "valet", "tommy",
"yokes", "epics", "trill", "pikes", "ozone", "caper", "chime", "frees", "famed", "leech", "smite", "neigh", "erode", "robed", "hoard", "salve", "conic", "gawky", "craze", "jacks", "gloat", "mushy", "rumps",
"fetus", "wince", "pinks", "shalt", "toots", "glens", "cooed", "rusts", "stews", "shred", "parka", "chugs", "winks", "clots", "shrew", "booed", "filmy", "juror", "dents", "gummy", "grays", "hooky", "butte",
"dogie", "poled", "reams", "fifes", "spank", "gayer", "tepid", "spook", "taint", "flirt", "rogue", "spiky", "opals", "miser", "cocky", "coyly", "balmy", "slosh", "brawl", "aphid", "faked", "hydra", "brags",
"chide", "yanks", "allay", "video", "altos", "eases", "meted", "chasm", "longs", "excel", "taffy", "impel", "savor", "koala", "quays", "dawns", "proxy", "clove", "duets", "dregs", "tardy", "briar", "grimy",
"ultra", "meaty", "halve", "wails", "suede", "mauve", "envoy", "arson", "coves", "gooey", "brews", "sofas", "chums", "amaze", "zooms", "abbot", "halos", "scour", "suing", "cribs", "sagas", "enema", "wordy",
"harps", "coupe", "molar", "flops", "weeps", "mints", "ashen", "felts", "askew", "munch", "mewed", "divan", "vices", "jumbo", "blobs", "blots", "spunk", "acrid", "topaz", "cubed", "clans", "flees", "slurs",
"gnaws", "welds", "fords", "emits", "agate", "pumas", "mends", "darks", "dukes", "plies", "canny", "hoots", "oozes", "lamed", "fouls", "clefs", "nicks", "mated", "skims", "brunt", "tuber", "tinge", "fates",
"ditty", "thins", "frets", "eider", "bayou", "mulch", "fasts", "amass", "damps", "morns", "friar", "palsy", "vista", "croon", "conch", "udder", "tacos", "skits", "mikes", "quits", "preen", "aster", "adder",
"elegy", "pulpy", "scows", "baled", "hovel", "lavas", "crave", "optic", "welts", "busts", "knave", "razed", "shins", "totes", "scoot", "dears", "crock", "mutes", "trims", "skein", "doted", "shuns", "veers",
"fakes", "yoked", "wooed", "hacks", "sprig", "wands", "lulls", "seers", "snobs", "nooks", "pined", "perky", "mooed", "frill", "dines", "booze", "tripe", "prong", "drips", "odder", "levee", "antic", "sidle",
"pithy", "corks", "yelps", "joker", "fleck", "buffs", "scram", "tiers", "bogey", "doled", "irate", "vales", "coped", "hails", "elude", "bulks", "aired", "vying", "stags", "strew", "cocci", "pacts", "scabs",
"silos", "dusts", "yodel", "terse", "jaded", "baser", "jibes", "foils", "sways", "forgo", "slays", "preys", "treks", "quell", "peeks", "assay", "lurks", "eject", "boars", "trite", "belch", "gnash", "wanes",
"lutes", "whims", "dosed", "chewy", "snipe", "umbra", "teems", "dozes", "kelps", "upped", "brawn", "doped", "shush", "rinds", "slush", "moron", "voile", "woken", "fjord", "sheik", "jests", "kayak", "slews",
"toted", "saner", "drape", "patty", "raves", "sulfa", "grist", "skied", "vixen", "civet", "vouch", "tiara", "homey", "moped", "runts", "serge", "kinky", "rills", "corns", "brats", "pries", "amble", "fries",
"loons", "tsars", "datum", "musky", "pigmy", "gnome", "ravel", "ovule", "icily", "liken", "lemur", "frays", "silts", "sifts", "plods", "ramps", "tress", "earls", "dudes", "waive", "karat", "jolts", "peons",
"beers", "horny", "pales", "wreak", "lairs", "lynch", "stank", "swoon", "idler", "abort", "blitz", "ensue", "atone", "bingo", "roves", "kilts", "scald", "adios", "cynic", "dulls", "memos", "elfin", "dales",
"peels", "peals", "bares", "sinus", "crone", "sable", "hinds", "shirk", "enrol", "wilts", "roams", "duped", "cysts", "mitts", "safes", "spats", "coops", "filet", "knell", "refit", "covey", "punks", "kilns",
"fitly", "abate", "talcs", "heeds", "duels", "wanly", "ruffs", "gauss", "lapel", "jaunt", "whelp", "cleat", "gauzy", "dirge", "edits", "wormy", "moats", "smear", "prods", "bowel", "frisk", "vests", "bayed",
"rasps", "tames", "delve", "embed", "befit", "wafer", "ceded", "novas", "feign", "spews", "larch", "huffs", "doles", "mamas", "hulks", "pried", "brims", "irked", "aspic", "swipe", "mealy", "skimp", "bluer",
"slake", "dowdy", "penis", "brays", "pupas", "egret", "flunk", "phlox", "gripe", "peony", "douse", "blurs", "darns", "slunk", "lefts", "chats", "inane", "vials", "stilt", "rinks", "woofs", "wowed", "bongs",
"frond", "ingot", "evict", "singe", "shyer", "flied", "slops", "dolts", "drool", "dells", "whelk", "hippy", "feted", "ether", "cocos", "hives", "jibed", "mazes", "trios", "sirup", "squab", "laths", "leers",
"pasta", "rifts", "lopes", "alias", "whirs", "diced", "slags", "lodes", "foxed", "idled", "prows", "plait", "malts", "chafe", "cower", "toyed", "chefs", "keels", "sties", "racer", "etude", "sucks", "sulks",
"micas", "czars", "copse", "ailed", "abler", "rabid", "golds", "croup", "snaky", "visas", "palls", "mopes", "boned", "wispy", "raved", "swaps", "junky", "doily", "pawns", "tamer", "poach", "baits", "damns",
"gumbo", "daunt", "prank", "hunks", "buxom", "heres", "honks", "stows", "unbar", "idles", "routs", "sages", "goads", "remit", "copes", "deign", "culls", "girds", "haves", "lucks", "stunk", "dodos", "shams",
"snubs", "icons", "usurp", "dooms", "hells", "soled", "comas", "paves", "maths", "perks", "limps", "wombs", "blurb", "daubs", "cokes", "sours", "stuns", "cased", "musts", "coeds", "cowed", "aping", "zoned",
"rummy", "fetes", "skulk", "quaff", "rajah", "deans", "reaps", "galas", "tills", "roved", "kudos", "toned", "pared", "scull", "vexes", "punts", "snoop", "bails", "dames", "hazes", "lores", "marts", "voids",
"ameba", "rakes", "adzes", "harms", "rears", "satyr", "swill", "hexes", "colic", "leeks", "hurls", "yowls", "ivies", "plops", "musks", "papaw", "jells", "bused", "cruet", "bided", "filch", "zests", "rooks",
"laxly", "rends", "loams", "basks", "sires", "carps", "pokey", "flits", "muses", "bawls", "shuck", "viler", "lisps", "peeps", "sorer", "lolls", "prude", "diked", "floss", "flogs", "scums", "dopes", "bogie",
"pinky", "leafs", "tubas", "scads", "lowed", "yeses", "biked", "qualm", "evens", "caned", "gawks", "whits", "wooly", "gluts", "romps", "bests", "dunce", "crony", "joist", "tunas", "boner", "malls", "parch",
"avers", "crams", "pares", "dally", "bigot", "kales", "flays", "leach", "gushy", "pooch", "huger", "slyer", "golfs", "mires", "flues", "loafs", "arced", "acnes", "neons", "fiefs", "dints", "dazes", "pouts",
"cored", "yules", "lilts", "beefs", "mutts", "fells", "cowls", "spuds", "lames", "jawed", "dupes", "deads", "bylaw", "noons", "nifty", "clued", "vireo", "gapes", "metes", "cuter", "maims", "droll", "cupid",
"mauls", "sedge", "papas", "wheys", "eking", "loots", "hilts", "meows", "beaus", "dices", "peppy", "riper", "fogey", "gists", "yogas", "gilts", "skews", "cedes", "zeals", "alums", "okays", "elope", "grump",
"wafts", "soots", "blimp", "hefts", "mulls", "hosed", "cress", "doffs", "ruder", "pixie", "waifs", "ousts", "pucks", "biers", "gulch", "suets", "hobos", "lints", "brans", "teals", "garbs", "pewee", "helms",
"turfs", "quips", "wends", "banes", "napes", "icier", "swats", "bagel", "hexed", "ogres", "goner", "gilds", "pyres", "lards", "bides", "paged", "talon", "flout", "medic", "veals", "putts", "dirks", "dotes",
"tippy", "blurt", "piths", "acing", "barer", "whets", "gaits", "wools", "dunks", "heros", "swabs", "dirts", "jutes", "hemps", "surfs", "okapi", "chows", "shoos", "dusks", "parry", "decal", "furls", "cilia",
"sears", "novae", "murks", "warps", "slues", "lamer", "saris", "weans", "purrs", "dills", "togas", "newts", "meany", "bunts", "razes", "goons", "wicks", "ruses", "vends", "geode", "drake", "judos", "lofts",
"pulps", "lauds", "mucks", "vises", "mocha", "oiled", "roman", "ethyl", "gotta", "fugue", "smack", "gourd", "bumpy", "radix", "fatty", "borax", "cubit", "cacti", "gamma", "focal", "avail", "papal", "golly",
"elite", "versa", "billy", "adieu", "annum", "howdy", "rhino", "norms", "bobby", "axiom", "setup", "yolks", "terns", "mixer", "genre", "knoll", "abode", "junta", "gorge", "combo", "alpha", "overt", "kinda",
"spelt", "prick", "nobly", "ephod", "audio", "modal", "veldt", "warty", "fluke", "bonny", "bream", "rosin", "bolls", "doers", "downs", "beady", "motif", "humph", "fella", "mould", "crepe", "kerns", "aloha",
"glyph", "azure", "riser", "blest", "locus", "lumpy", "beryl", "wanna", "brier", "tuner", "rowdy", "mural", "timer", "canst", "krill", "quoth", "lemme", "triad", "tenon", "amply", "deeps", "padre", "leant",
"pacer", "octal", "dolly", "trans", "sumac", "foamy", "lolly", "giver", "quipu", "codex", "manna", "unwed", "vodka", "ferny", "salon", "duple", "boron", "revue", "crier", "alack", "inter", "dilly", "whist",
"cults", "spake", "reset", "loess", "decor", "mover", "verve", "ethic", "gamut", "lingo", "dunno", "align", "sissy", "incur", "reedy", "avant", "piper", "waxer", "calyx", "basil", "coons", "seine", "piney",
"lemma", "trams", "winch", "whirr", "saith", "ionic", "heady", "harem", "tummy", "sally", "shied", "dross", "farad", "saver", "tilde", "jingo", "bower", "serif", "facto", "belle", "inset", "bogus", "caved",
"forte", "sooty", "bongo", "toves", "credo", "basal", "yella", "aglow", "glean", "gusto", "hymen", "ethos", "terra", "brash", "scrip", "swash", "aleph", "tinny", "itchy", "wanta", "trice", "jowls", "gongs",
"garde", "boric", "twill", "sower", "henry", "awash", "libel", "spurn", "sabre", "rebut", "penal", "obese", "sonny", "quirt", "mebbe", "tacit", "greek", "xenon", "hullo", "pique", "roger", "negro", "hadst",
"gecko", "beget", "uncut", "aloes", "louis", "quint", "clunk", "raped", "salvo", "diode", "matey", "hertz", "xylem", "kiosk", "apace", "cawed", "peter", "wench", "cohos", "sorta", "gamba", "bytes", "tango",
"nutty", "axial", "aleck", "natal", "clomp", "gored", "siree", "bandy", "gunny", "runic", "whizz", "rupee", "fated", "wiper", "bards", "briny", "staid", "hocks", "ochre", "yummy", "gents", "soupy", "roper",
"swath", "cameo", "edger", "spate", "gimme", "ebbed", "breve", "theta", "deems", "dykes", "servo", "telly", "tabby", "tares", "blocs", "welch", "ghoul", "vitae", "cumin", "dinky", "bronc", "tabor", "teeny",
"comer", "borer", "sired", "privy", "mammy", "deary", "gyros", "sprit", "conga", "quire", "thugs", "furor", "bloke", "runes", "bawdy", "cadre", "toxin", "annul", "egged", "anion", "nodes", "picky", "stein",
"jello", "audit", "echos", "fagot", "letup", "eyrie", "fount", "caped", "axons", "amuck", "banal", "riled", "petit", "umber", "miler", "fibre", "agave", "bated", "bilge", "vitro", "feint", "pudgy", "mater",
"manic", "umped", "pesky", "strep", "slurp", "pylon", "puree", "caret", "temps", "newel", "yawns", "seedy", "treed", "coups", "rangy", "brads", "mangy", "loner", "circa", "tibia", "afoul", "mommy", "titer",
"carne", "kooky", "motes", "amity", "suave", "hippo", "curvy", "samba", "newsy", "anise", "imams", "tulle", "aways", "liven", "hallo", "wales", "opted", "canto", "idyll", "bodes", "curio", "wrack", "hiker",
"chive", "yokel", "dotty", "demur", "cusps", "specs", "quads", "laity", "toner", "decry", "writs", "saute", "clack", "aught", "logos", "tipsy", "natty", "ducal", "bidet", "bulgy", "metre", "lusts", "unary",
"goeth", "baler", "sited", "shies", "hasps", "brung", "holed", "swank", "looky", "melee", "huffy", "loamy", "pimps", "titan", "binge", "shunt", "femur", "libra", "seder", "honed", "annas", "coypu", "shims",
"zowie", "jihad", "savvy", "nadir", "basso", "monic", "maned", "mousy", "omega", "laver", "prima", "picas", "folio", "mecca", "reals", "troth", "testy", "balky", "crimp", "chink", "abets", "splat", "abaci",
"vaunt", "cutie", "pasty", "moray", "levis", "ratty", "islet", "joust", "motet", "viral", "nukes", "grads", "comfy", "voila", "woozy", "blued", "whomp", "sward", "metro", "skeet", "chine", "aerie", "bowie",
"tubby", "emirs", "coati", "unzip", "slobs", "trike", "funky", "ducat", "dewey", "skoal", "wadis", "oomph", "taker", "minim", "getup", "stoic", "synod", "runty", "flyby", "braze", "inlay", "venue", "louts",
"peaty", "orlon", "humpy", "radon", "beaut", "raspy", "unfed", "crick", "nappy", "vizor", "yipes", "rebus", "divot", "kiwis", "vetch", "squib", "sitar", "kiddo", "dyers", "cotta", "matzo", "lager", "zebus",
"crass", "dacha", "kneed", "dicta", "fakir", "knurl", "runny", "unpin", "julep", "globs", "nudes", "sushi", "tacky", "stoke", "kaput", "butch", "hulas", "croft", "achoo", "genii", "nodal", "outgo", "spiel",
"viols", "fetid", "cagey", "fudgy", "epoxy", "leggy", "hanky", "lapis", "felon", "beefy", "coots", "melba", "caddy", "segue", "betel", "frizz", "drear", "kooks", "turbo", "hoagy", "moult", "helix", "zonal",
"arias", "nosey", "paean", "lacey", "banns", "swain", "fryer", "retch", "tenet", "gigas", "whiny", "ogled", "rumen", "begot", "cruse", "abuts", "riven", "balks", "sines", "sigma", "abase", "ennui", "gores",
"unset", "augur", "sated", "odium", "latin", "dings", "moire", "scion", "henna", "kraut", "dicks", "lifer", "prigs", "bebop", "gages", "gazer", "fanny", "gibes", "aural", "tempi", "hooch", "rapes", "snuck",
"harts", "techs", "emend", "ninny", "guava", "scarp", "liege", "tufty", "sepia", "tomes", "carob", "emcee", "prams", "poser", "verso", "hubba", "joule", "baize", "blips", "scrim", "cubby", "clave", "winos",
"rearm", "liens", "lumen", "chump", "nanny", "trump", "fichu", "chomp", "homos", "purty", "maser", "woosh", "patsy", "shill", "rusks", "avast", "swami", "boded", "ahhhh", "lobed", "natch", "shish", "tansy",
"snoot", "payer", "altho", "sappy", "laxer", "hubby", "aegis", "riles", "ditto", "jazzy", "dingo", "quasi", "septa", "peaky", "lorry", "heerd", "bitty", "payee", "seamy", "apses", "imbue", "belie", "chary",
"spoof", "phyla", "clime", "babel", "wacky", "sumps", "skids", "khans", "crypt", "inure", "nonce", "outen", "faire", "hooey", "anole", "kazoo", "calve", "limbo", "argot", "ducky", "faker", "vibes", "gassy",
"unlit", "nervy", "femme", "biter", "fiche", "boors", "gaffe", "saxes", "recap", "synch", "facie", "dicey", "ouija", "hewer", "legit", "gurus", "edify", "tweak", "caron", "typos", "rerun", "polly", "surds",
"hamza", "nulls", "hater", "lefty", "mogul", "mafia", "debug", "pates", "blabs", "splay", "talus", "porno", "moola", "nixed", "kilos", "snide", "horsy", "gesso", "jaggy", "trove", "nixes", "creel", "pater",
"iotas", "cadge", "skyed", "hokum", "furze", "ankhs", "curie", "nutsy", "hilum", "remix", "angst", "burls", "jimmy", "veiny", "tryst", "codon", "befog", "gamed", "flume", "axman", "doozy", "lubes", "rheas",
"bozos", "butyl", "kelly", "mynah", "jocks", "donut", "avian", "wurst", "chock", "quash", "quals", "hayed", "bombe", "cushy", "spacy", "puked", "leery", "thews", "prink", "amens", "tesla", "intro", "fiver",
"frump", "capos", "opine", "coder", "namer", "jowly", "pukes", "haled", "chard", "duffs", "bruin", "reuse", "whang", "toons", "frats", "silty", "telex", "cutup", "nisei", "neato", "decaf", "softy", "bimbo",
"adlib", "loony", "shoed", "agues", "peeve", "noway", "gamey", "sarge", "reran", "epact", "potty", "coned", "upend", "narco", "ikats", "whorl", "jinks", "tizzy", "weepy", "posit", "marge", "vegan", "clops",
"numbs", "reeks", "rubes", "rower", "biped", "tiffs", "hocus", "hammy", "bunco", "fixit", "tykes", "chaws", "yucky", "hokey", "resew", "maven", "adman", "scuzz", "slogs", "souse", "nacho", "mimed", "melds",
"boffo", "debit", "pinup", "vagus", "gulag", "randy", "bosun", "educe", "faxes", "auras", "pesto", "antsy", "betas", "fizzy", "dorky", "snits", "moxie", "thane", "mylar", "nobby", "gamin", "gouty", "esses",
"goyim", "paned", "druid", "jades", "rehab", "gofer", "tzars", "octet", "homed", "socko", "dorks", "eared", "anted", "elide", "fazes", "oxbow", "dowse", "situs", "macaw", "scone", "drily", "hyper", "salsa",
"mooch", "gated", "unjam", "lipid", "mitre", "venal", "knish", "ritzy", "divas", "torus", "mange", "dimer", "recut", "meson", "wined", "fends", "phage", "fiats", "caulk", "cavil", "panty", "roans", "bilks",
"hones", "botch", "estop", "sully", "sooth", "gelds", "ahold", "raper", "pager", "fixer", "infix", "hicks", "tuxes", "plebe", "twits", "abash", "twixt", "wacko", "primp", "nabla", "girts", "miffs", "emote",
"xerox", "rebid", "shahs", "rutty", "grout", "grift", "deify", "biddy", "kopek", "semis", "bries", "acmes", "piton", "hussy", "torts", "disco", "whore", "boozy", "gibed", "vamps", "amour", "soppy", "gonzo",
"durst", "wader", "tutus", "perms", "catty", "glitz", "brigs", "nerds", "barmy", "gizmo", "owlet", "sayer", "molls", "shard", "whops", "comps", "corer", "colas", "matte", "droid", "ploys", "vapid", "cairn",
"deism", "mixup", "yikes", "prosy", "raker", "flubs", "whish", "reify", "craps", "shags", "clone", "hazed", "macho", "recto", "refix", "drams", "biker", "aquas", "porky", "doyen", "exude", "goofs", "divvy",
"noels", "jived", "hulky", "cager", "harpy", "oldie", "vivas", "admix", "codas", "zilch", "deist", "orcas", "retro", "pilaf", "parse", "rants", "zingy", "toddy", "chiff", "micro", "veeps", "girly", "nexus",
"demos", "bibbs", "antes", "lulus", "gnarl", "zippy", "ivied", "epees", "wimps", "tromp", "grail", "yoyos", "poufs", "hales", "roust", "cabal", "rawer", "pampa", "mosey", "kefir", "burgs", "unmet", "cuspy",
"boobs", "boons", "hypes", "dynes", "nards", "lanai", "yogis", "sepal", "quark", "toked", "prate", "ayins", "hawed", "swigs", "vitas", "toker", "doper", "bossa", "linty", "foist", "mondo", "stash", "kayos",
"twerp", "zesty", "capon", "wimpy", "rewed", "fungo", "tarot", "frosh", "kabob", "pinko", "redid", "mimeo", "heist", "tarps", "lamas", "sutra", "dinar", "whams", "busty", "spays", "mambo", "nabob", "preps",
"odour", "cabby", "conks", "sluff", "dados", "houri", "swart", "balms", "gutsy", "faxed", "egads", "pushy", "retry", "agora", "drubs", "daffy", "chits", "mufti", "karma", "lotto", "toffs", "burps", "deuce",
"zings", "kappa", "clads", "doggy", "duper", "scams", "ogler", "mimes", "throe", "zetas", "waled", "promo", "blats", "muffs", "oinks", "viand", "coset", "finks", "faddy", "minis", "snafu", "sauna", "usury",
"muxes", "craws", "stats", "condo", "coxes", "loopy", "dorms", "ascot", "dippy", "execs", "dopey", "envoi", "umpty", "gismo", "fazed", "strop", "jives", "slims", "batik", "pings", "sonly", "leggo", "pekoe",
"prawn", "luaus", "campy", "oodle", "prexy", "proms", "touts", "ogles", "tweet", "toady", "naiad", "hider", "nuked", "fatso", "sluts", "obits", "narcs", "tyros", "delis", "wooer", "hyped", "poset", "byway",
"texas", "scrod", "avows", "futon", "torte", "tuple", "carom", "kebab", "tamps", "jilts", "duals", "artsy", "repro", "modem", "toped", "psych", "sicko", "klutz", "tarns", "coxed", "drays", "cloys", "anded",
"piker", "aimer", "suras", "limos", "flack", "hapax", "dutch", "mucky", "shire", "klieg", "staph", "layup", "tokes", "axing", "toper", "duvet", "cowry", "profs", "blahs", "addle", "sudsy", "batty", "coifs",
"suety", "gabby", "hafta", "pitas", "gouda", "deice", "taupe", "topes", "duchy", "nitro", "carny", "limey", "orals", "hirer", "taxer", "roils", "ruble", "elate", "dolor", "wryer", "snots", "quais", "coked",
"gimel", "gorse", "minas", "goest", "agape", "manta", "jings", "iliac", "admen", "offen", "cills", "offal", "lotta", "bolas", "thwap", "alway", "boggy", "donna", "locos", "belay", "gluey", "bitsy", "mimsy",
"hilar", "outta", "vroom", "fetal", "raths", "renal", "dyads", "crocs", "vires", "culpa", "kivas", "feist", "teats", "thats", "yawls", "whens", "abaca", "ohhhh", "aphis", "fusty", "eclat", "perdu", "mayst",
"exeat", "molly", "supra", "wetly", "plasm", "buffa", "semen", "pukka", "tagua", "paras", "stoat", "secco", "carte", "haute", "molal", "shads", "forma", "ovoid", "pions", "modus", "bueno", "rheum", "scurf",
"parer", "ephah", "doest", "sprue", "flams", "molto", "dieth", "choos", "miked", "bronx", "goopy", "bally", "plumy", "moony", "morts", "yourn", "bipod", "spume", "algal", "ambit", "mucho", "spued", "dozer",
"harum", "groat", "skint", "laude", "thrum", "pappy", "oncet", "rimed", "gigue", "limed", "plein", "redly", "humpf", "lites", "seest", "grebe", "absit", "thanx", "pshaw", "yawps", "plats", "payed", "areal",
"tilth", "youse", "gwine", "thees", "watsa", "lento", "spitz", "yawed", "gipsy", "sprat", "cornu", "amahs", "blowy", "wahoo", "lubra", "mecum", "whooo", "coqui", "sabra", "edema", "mrads", "dicot", "astro",
"kited", "ouzel", "didos", "grata", "bonne", "axmen", "klunk", "summa", "laves", "purls", "yawny", "teary", "masse", "largo", "bazar", "pssst", "sylph", "lulab", "toque", "fugit", "plunk", "ortho", "lucre",
"cooch", "whipt", "folky", "tyres", "wheee", "corky", "injun", "solon", "didot", "kerfs", "rayed", "wassa", "chile", "begat", "nippy", "litre", "magna", "rebox", "hydro", "milch", "brent", "gyves", "lazed",
"feued", "mavis", "inapt", "baulk", "casus", "scrum", "wised", "fossa", "dower", "kyrie", "bhoys", "scuse", "feuar", "ohmic", "juste", "ukase", "beaux", "tusky", "orate", "musta", "lardy", "intra", "quiff",
"epsom", "neath", "ocher", "tared", "homme", "mezzo", "corms", "psoas", "beaky", "terry", "infra", "spivs", "tuans", "belli", "bergs", "anima", "weirs", "mahua", "scops", "manse", "titre", "curia", "kebob",
"cycad", "talky", "fucks", "tapis", "amide", "dolce", "sloes", "jakes", "russe", "blash", "tutti", "pruta", "panga", "blebs", "tench", "swarf", "herem", "missy", "merse", "pawky", "limen", "vivre", "chert",
"unsee", "tiros", "brack", "foots", "welsh", "fosse", "knops", "ileum", "noire", "firma", "podgy", "laird", "thunk", "shute", "rowan", "shoji", "poesy", "uncap", "fames", "glees", "costa", "turps", "fores",
"solum", "imago", "byres", "fondu", "coney", "polis", "dictu", "kraal", "sherd", "mumbo", "wroth", "chars", "unbox", "vacuo", "slued", "weest", "hades", "wiled", "syncs", "muser", "excon", "hoars", "sibyl",
"passe", "joeys", "lotsa", "lepta", "shays", "bocks", "endue", "darer", "nones", "ileus", "plash", "busby", "wheal", "buffo", "yobbo", "biles", "poxes", "rooty", "licit", "terce", "bromo", "hayey", "dweeb",
"imbed", "saran", "bruit", "punky", "softs", "biffs", "loppy", "agars", "aquae", "livre", "biome", "bunds", "shews", "diems", "ginny", "degum", "polos", "desex", "unman", "dungy", "vitam", "wedgy", "glebe",
"apers", "ridgy", "roids", "wifey", "vapes", "whoas", "bunko", "yolky", "ulnas", "reeky", "bodge", "brant", "davit", "deque", "liker", "jenny", "tacts", "fulls", "treap", "ligne", "acked", "refry", "vower",
"aargh", "churl", "momma", "gaols", "whump", "arras", "marls", "tiler", "grogs", "memes", "midis", "tided", "haler", "duces", "twiny", "poste", "unrig", "prise", "drabs", "quids", "facer", "spier", "baric",
"geoid", "remap", "trier", "gunks", "steno", "stoma", "airer", "ovate", "torah", "apian", "smuts", "pocks", "yurts", "exurb", "defog", "nuder", "bosky", "nimbi", "mothy", "joyed", "labia", "pards", "jammy",
"bigly", "faxer", "hoppy", "nurbs", "cotes", "dishy", "vised", "celeb", "pismo", "casas", "withs", "dodgy", "scudi", "mungs", "muons", "ureas", "ioctl", "unhip", "krone", "sager", "verst", "expat", "gronk",
"uvula", "shawm", "bilgy", "braes", "cento", "webby", "lippy", "gamic", "lordy", "mazed", "tings", "shoat", "faery", "wirer", "diazo", "carer", "rater", "greps", "rente", "zloty", "viers", "unapt", "poops",
"fecal", "kepis", "taxon", "eyers", "wonts", "spina", "stoae", "yenta", "pooey", "buret", "japan", "bedew", "hafts", "selfs", "oared", "herby", "pryer", "oakum", "dinks", "titty", "sepoy", "penes", "fusee",
"winey", "gimps", "nihil", "rille", "giber", "ousel", "umiak", "cuppy", "hames", "shits", "azine", "glads", "tacet", "bumph", "coyer", "honky", "gamer", "gooky", "waspy", "sedgy", "bents", "varia", "djinn",
"junco", "pubic", "wilco", "lazes", "idyls", "lupus", "rives", "snood", "schmo", "spazz", "finis", "noter", "pavan", "orbed", "bates", "pipet", "baddy", "goers", "shako", "stets", "sebum", "seeth", "lobar",
"raver", "ajuga", "riced", "velds", "dribs", "ville", "dhows", "unsew", "halma", "krona", "limby", "jiffs", "treys", "bauds", "pffft", "mimer", "plebs", "caner", "jiber", "cuppa", "washy", "chuff", "unarm",
"yukky", "styes", "waker", "flaks", "maces", "rimes", "gimpy", "guano", "liras", "kapok", "scuds", "bwana", "oring", "aider", "prier", "klugy", "monte", "golem", "velar", "firer", "pieta", "umbel", "campo",
"unpeg", "fovea", "abeam", "boson", "asker", "goths", "vocab", "vined", "trows", "tikis", "loper", "indie", "boffs", "spang", "grapy", "tater", "ichor", "kilty", "lochs", "supes", "degas", "flics", "torsi",
"beths", "weber", "resaw", "lawny", "coven", "mujik", "relet", "therm", "heigh", "shnor", "trued", "zayin", "liest", "barfs", "bassi", "qophs", "roily", "flabs", "punny", "okras", "hanks", "dipso", "nerfs",
"fauns", "calla", "pseud", "lurer", "magus", "obeah", "atria", "twink", "palmy", "pocky", "pends", "recta", "plonk", "slaws", "keens", "nicad", "pones", "inker", "whews", "groks", "mosts", "trews", "ulnar",
"gyppy", "cocas", "expos", "eruct", "oiler", "vacua", "dreck", "dater", "arums", "tubal", "voxel", "dixit", "beery", "assai", "lades", "actin", "ghoti", "buzzy", "meads", "grody", "ribby", "clews", "creme",
"email", "pyxie", "kulak", "bocci", "rived", "duddy", "hoper", "lapin", "wonks", "petri", "phial", "fugal", "holon", "boomy", "duomo", "musos", "shier", "hayer", "porgy", "hived", "litho", "fisty", "stagy",
"luvya", "maria", "smogs", "asana", "yogic", "slomo", "fawny", "amine", "wefts", "gonad", "twirp", "brava", "plyer", "fermi", "loges", "niter", "revet", "unate", "gyved", "totty", "zappy", "honer", "giros",
"dicer", "calks", "luxes", "monad", "cruft", "quoin", "fumer", "amped", "shlep", "vinca", "yahoo", "vulva", "zooey", "dryad", "nixie", "moper", "iambs", "lunes", "nudie", "limns", "weals", "nohow", "miaow",
"gouts", "mynas", "mazer", "kikes", "oxeye", "stoup", "jujus", "debar", "pubes", "taels", "defun", "rands", "blear", "paver", "goosy", "sprog", "oleos", "toffy", "pawer", "maced", "crits", "kluge", "tubed",
"sahib", "ganef", "scats", "sputa", "vaned", "acned", "taxol", "plink", "oweth", "tribs", "resay", "boule", "thous", "haply", "glans", "maxis", "bezel", "antis", "porks", "quoit", "alkyd", "glary", "beamy",
"hexad", "bonks", "tecum", "kerbs", "filar", "frier", "redux", "abuzz", "fader", "shoer", "couth", "trues", "guyed", "goony", "booky", "fuzes", "hurly", "genet", "hodad", "calix", "filer", "pawls", "iodic",
"utero", "henge", "unsay", "liers", "piing", "weald", "sexed", "folic", "poxed", "cunts", "anile", "kiths", "becks", "tatty", "plena", "rebar", "abled", "toyer", "attar", "teaks", "aioli", "awing", "anent",
"feces", "redip", "wists", "prats", "mesne", "muter", "smurf", "owest", "bahts", "lossy", "ftped", "hunky", "hoers", "slier", "sicks", "fatly", "delft", "hiver", "himbo", "pengo", "busks", "loxes", "zonks",
"ilium", "aport", "ikons", "mulct", "reeve", "civvy", "canna", "barfy", "kaiak", "scudo", "knout", "gaper", "bhang", "pease", "uteri", "lases", "paten", "rasae", "axels", "stoas", "ombre", "styli", "gunky",
"hazer", "kenaf", "ahoys", "ammos", "weeny", "urger", "kudzu", "pluck", "pleat", "parse", "farce", "ducky", "paren", "bolos", "fetor", "nitty", "techy", "lieth", "somas", "darky", "villi", "gluon", "janes", "cants", "farts", "socle", "jinns", "ruing",
"slily", "ricer", "hadda", "wowee", "rices", "nerts", "cauls", "swive", "lilty", "micks", "arity", "pasha", "finif", "oinky", "gutty", "tetra", "wises", "wolds", "balds", "picot", "whats", "shiki", "bungs",
"snarf", "legos", "dungs", "stogy", "berms", "tangs", "vails", "roods", "morel", "sware", "elans", "latus", "gules", "razer", "doxie", "buena", "overs", "gutta", "zincs", "nates", "kirks", "tikes", "donee",
"jerry", "mohel", "ceder", "doges", "unmap", "folia", "rawly", "snark", "topoi", "ceils", "immix", "yores", "diest", "bubba", "pomps", "forky", "turdy", "lawzy", "poohs", "worts", "gloms", "beano", "muley",
"barky", "tunny", "auric", "funks", "gaffs", "cordy", "curdy", "lisle", "toric", "soyas", "reman", "mungy", "carpy", "apish", "oaten", "gappy", "aurae", "bract", "rooky", "axled", "burry", "sizer", "proem",
"turfy", "impro", "mashy", "miens", "nonny", "olios", "grook", "sates", "agley", "corgi", "dashy", "doser", "dildo", "apsos", "xored", "laker", "playa", "selah", "malty", "dulse", "frigs", "demit", "whoso",
"rials", "sawer", "spics", "bedim", "snugs", "fanin", "azoic", "icers", "suers", "wizen", "koine", "topos", "shirr", "rifer", "feral", "laded", "lased", "turds", "swede", "easts", "cozen", "unhit", "pally",
"aitch", "sedum", "coper", "ruche", "geeks", "swags", "etext", "algin", "offed", "ninja", "holer", "doter", "toter", "besot", "dicut", "macer", "peens", "pewit", "redox", "poler", "yecch", "fluky", "doeth",
"twats", "cruds", "bebug", "bider", "stele", "hexer", "wests", "gluer", "pilau", "abaft", "whelm", "lacer", "inode", "tabus", "gator", "cuing", "refly", "luted", "cukes", "bairn", "bight", "arses", "crump",
"loggy", "blini", "spoor", "toyon", "harks", "wazoo", "fenny", "naves", "keyer", "tufas", "morph", "rajas", "typal", "spiff", "oxlip", "unban", "mussy", "finny", "rimer", "login", "molas", "cirri", "huzza",
"agone", "unsex", "unwon", "peats", "toile", "zombi", "dewed", "nooky", "alkyl", "ixnay", "dovey", "holey", "cuber", "amyls", "podia", "chino", "apnea", "prims", "lycra", "johns", "primo", "fatwa", "egger",
"hempy", "snook", "hying", "fuzed", "barms", "crink", "moots", "yerba", "rhumb", "unarc", "direr", "munge", "eland", "nares", "wrier", "noddy", "atilt", "jukes", "ender", "thens", "unfix", "doggo", "zooks",
"diddy", "shmoo", "brusk", "prest", "curer", "pasts", "kelpy", "bocce", "kicky", "taros", "lings", "dicky", "nerdy", "abend", "stela", "biggy", "laved", "baldy", "pubis", "gooks", "wonky", "stied", "hypos",
"assed", "spumy", "osier", "roble", "rumba", "biffy", "pupal", "aback", "abase", "abate", "abaya", "abbey", "abbot", "abets", "abhor", "abide", "abode", "abort", "about", "above", "abuse", "abuts", "abyss", "ached", "aches", "acids", "acing", "ackee", "acorn", "acres",
"acrid", "acted", "actin", "actor", "acute", "adage", "adapt", "added", "adder", "addle", "adept", "adieu", "adios", "adits", "adman", "admin", "admit", "adobe", "adobo", "adopt", "adore", "adorn", "adult",
"adzes", "aegis", "aeons", "aerie", "affix", "afire", "afoot", "afore", "after", "again", "agape", "agate", "agave", "agent", "aggro", "agile", "aging", "aglow", "agony", "agora", "agree", "ahead", "ahold",
"aided", "aider", "aides", "ailed", "aimed", "aimer", "aioli", "aired", "aisle", "alarm", "album", "alder", "aleph", "alert", "algae", "algal", "alias", "alibi", "alien", "align", "alike", "alive", "alkyd",
"alkyl", "allay", "alley", "allot", "allow", "alloy", "allyl", "aloes", "aloft", "aloha", "alone", "along", "aloof", "aloud", "alpha", "altar", "alter", "altos", "alums", "amass", "amaze", "amber", "ambit",
"amble", "ambos", "amend", "amide", "amine", "amino", "amiss", "amity", "amnio", "among", "amour", "amped", "ample", "amply", "amuse", "ancho", "angel", "anger", "angle", "angry", "angst", "anima", "anime",
"anion", "anise", "ankle", "annas", "annex", "annoy", "annul", "anode", "anole", "antic", "antis", "antsy", "anvil", "aorta", "apace", "apart", "aphid", "apnea", "apple", "apply", "apron", "apses", "apter",
"aptly", "aquas", "arbor", "ardor", "areal", "areas", "areca", "arena", "argon", "argot", "argue", "argus", "arias", "arils", "arise", "armed", "armor", "aroma", "arose", "array", "arrow", "arses", "arson",
"artsy", "asana", "ascot", "ashen", "ashes", "aside", "asked", "asker", "askew", "aspen", "aspic", "assay", "asses", "asset", "aster", "astir", "asura", "atlas", "atman", "atoll", "atoms", "atone", "atopy",
"attic", "audio", "audit", "auger", "aught", "augur", "aunts", "aunty", "aural", "auras", "autos", "auxin", "avail", "avers", "avert", "avian", "avoid", "avows", "await", "awake", "award", "aware", "awash",
"awful", "awoke", "axels", "axial", "axils", "axing", "axiom", "axion", "axles", "axons", "azide", "azole", "azure", "babel", "babes", "babka", "backs", "bacon", "baddy", "badge", "badly", "bagel", "baggy",
"bails", "bairn", "baits", "baize", "baked", "baker", "bakes", "baldy", "baled", "baler", "bales", "balks", "balky", "balls", "balms", "balmy", "balsa", "banal", "bands", "bandy", "banes", "bangs", "banjo",
"banks", "barbs", "bards", "bared", "barer", "bares", "barge", "barks", "barmy", "barns", "baron", "barre", "basal", "based", "baser", "bases", "basic", "basil", "basin", "basis", "basks", "basso", "bassy",
"baste", "batch", "bated", "bathe", "baths", "batik", "baton", "batts", "batty", "bawdy", "bawls", "bayed", "bayou", "beach", "beads", "beady", "beaks", "beams", "beamy", "beans", "beard", "bears", "beast",
"beats", "beaus", "beaut", "beaux", "bebop", "becks", "beech", "beefs", "beefy", "beeps", "beers", "beery", "beets", "befit", "began", "beget", "begin", "begun", "beige", "being", "belay", "belch", "belie",
"belle", "bells", "belly", "below", "belts", "bench", "bends", "bendy", "bento", "bents", "beret", "bergs", "berms", "berry", "berth", "beryl", "beset", "bests", "betas", "betel", "betta", "bevel", "bezel",
"bhaji", "bible", "bicep", "biddy", "bided", "bides", "bidet", "bight", "bigot", "bijou", "biked", "biker", "bikes", "biles", "bilge", "bills", "billy", "bimbo", "bindi", "binds", "binge", "bingo", "biome",
"biota", "bipod", "birch", "birds", "birth", "bison", "bitch", "biter", "bites", "bitsy", "bitty", "black", "blade", "blame", "bland", "blank", "blare", "blase", "blast", "blaze", "bleak", "bleat", "blebs",
"bleed", "bleep", "blend", "bless", "blimp", "blind", "bling", "blini", "blink", "blips", "bliss", "blitz", "bloat", "blobs", "block", "blocs", "blogs", "bloke", "blond", "blood", "bloom", "bloop", "blots",
"blown", "blows", "blued", "blues", "bluey", "bluff", "blunt", "blurb", "blurs", "blurt", "blush", "board", "boars", "boast", "boats", "bobby", "bocce", "boche", "boded", "bodes", "boffo", "bogey", "boggy",
"bogie", "bogus", "boils", "bolas", "boles", "bolls", "bolts", "bolus", "bombe", "bombs", "bonds", "boned", "boner", "bones", "boney", "bongo", "bongs", "bonks", "bonny", "bonus", "boobs", "booby", "booed",
"books", "booms", "boomy", "boons", "boors", "boost", "booth", "boots", "booty", "booze", "boozy", "boppy", "borax", "bored", "borer", "bores", "boric", "borne", "boron", "bosom", "boson", "bossy", "bosun",
"botch", "bough", "boule", "bound", "bouts", "bowed", "bowel", "bower", "bowls", "boxed", "boxer", "boxes", "boyar", "boyos", "bozos", "brace", "bract", "brads", "brags", "braid", "brain", "brake", "brand",
"brans", "brash", "brass", "brats", "brave", "bravo", "brawl", "brawn", "brays", "braze", "bread", "break", "bream", "breed", "brews", "briar", "bribe", "brick", "bride", "brief", "brier", "brigs", "brims",
"brine", "bring", "brink", "briny", "brisk", "brits", "broad", "broch", "broil", "broke", "brome", "bronc", "brood", "brook", "broom", "broth", "brown", "brows", "bruin", "bruit", "brunt", "brush", "brute",
"bubba", "bucks", "buddy", "budge", "buffs", "buggy", "bugle", "build", "built", "bulbs", "bulge", "bulks", "bulky", "bulla", "bulls", "bully", "bumps", "bumpy", "bunch", "bunds", "bundt", "bunks", "bunny",
"bunts", "buoys", "burbs", "burgs", "burka", "burly", "burns", "burnt", "burps", "burqa", "burro", "burrs", "bursa", "burst", "bused", "buses", "bushy", "busts", "busty", "butch", "butte", "butts", "buxom",
"buyer", "buzzy", "bylaw", "byres", "bytes", "byway", "cabal", "cabby", "caber", "cabin", "cable", "cacao", "cache", "cacti", "caddy", "cadet", "cadre", "cafes", "caged", "cages", "cagey", "cairn", "caked",
"cakes", "cakey", "calfs", "calif", "calla", "calls", "calms", "calve", "calyx", "camel", "cameo", "campo", "camps", "campy", "canal", "candy", "caned", "canes", "canid", "canna", "canny", "canoe", "canon",
"canto", "caped", "caper", "capes", "capon", "capos", "caput", "carat", "carbo", "carbs", "cards", "cared", "carer", "cares", "cargo", "carob", "carol", "carom", "carps", "carry", "carte", "carts", "carve",
"cased", "cases", "casks", "caste", "casts", "catch", "cater", "catty", "caulk", "cause", "caved", "caver", "caves", "cavil", "cease", "cecal", "cecum", "cedar", "ceded", "cedes", "ceili", "celeb", "cello",
"cells", "celts", "cents", "chads", "chafe", "chaff", "chain", "chair", "chalk", "champ", "chana", "chant", "chaos", "chaps", "chard", "charm", "chars", "chart", "chase", "chasm", "chats", "cheap", "cheat",
"check", "cheek", "cheep", "cheer", "chefs", "chemo", "chert", "chess", "chest", "chews", "chewy", "chica", "chick", "chico", "chide", "chief", "child", "chile", "chili", "chill", "chime", "chimp", "china",
"chine", "ching", "chino", "chins", "chips", "chirp", "chits", "chive", "chock", "choir", "choke", "chomp", "chops", "chord", "chore", "chose", "chows", "chubs", "chuck", "chuff", "chugs", "chump", "chums",
"chunk", "churn", "chute", "cider", "cigar", "cinch", "circa", "cisco", "cited", "cites", "civet", "civic", "civil", "civvy", "clack", "clade", "claim", "clamp", "clams", "clang", "clank", "clans", "claps",
"clash", "clasp", "class", "clave", "claws", "clays", "clean", "clear", "cleat", "clefs", "cleft", "clerk", "click", "cliff", "climb", "clime", "cline", "cling", "clink", "clips", "cloak", "clock", "clods",
"clogs", "clomp", "clone", "close", "cloth", "clots", "cloud", "clout", "clove", "clown", "clubs", "cluck", "clued", "clues", "clump", "clung", "clunk", "coach", "coals", "coast", "coati", "coats", "cobia",
"cobra", "cocci", "cocks", "cocky", "cocoa", "codas", "codec", "coded", "coder", "codes", "codex", "codon", "coeds", "cohos", "coifs", "coils", "coins", "cokes", "colas", "colds", "coles", "colic", "colin",
"colon", "color", "colts", "comas", "combo", "combs", "comer", "comes", "comet", "comfy", "comic", "comma", "commo", "compo", "comps", "comte", "conch", "condo", "coned", "cones", "conga", "congo", "conic",
"conks", "cooed", "cooks", "cools", "coops", "coopt", "coped", "copes", "copra", "copse", "coral", "cords", "cored", "corer", "cores", "corgi", "corks", "corky", "corms", "corns", "cornu", "corny", "corps",
"costs", "cotta", "couch", "cough", "could", "count", "coupe", "coups", "court", "coven", "cover", "coves", "covet", "covey", "cowed", "cower", "cowls", "coyly", "crabs", "crack", "craft", "crags", "cramp",
"crams", "crane", "crank", "crape", "craps", "crash", "crass", "crate", "crave", "crawl", "craws", "craze", "crazy", "creak", "cream", "credo", "creed", "creek", "creel", "creep", "creme", "crepe", "crept",
"cress", "crest", "crews", "cribs", "crick", "cried", "crier", "cries", "crime", "crimp", "crisp", "crits", "croak", "crock", "crocs", "croft", "crone", "crony", "crook", "croon", "crops", "cross", "croup",
"crowd", "crown", "crows", "crude", "cruel", "cruet", "crumb", "cruse", "crush", "crust", "crypt", "cubby", "cubed", "cubes", "cubic", "cubit", "cuddy", "cuffs", "culls", "culpa", "cults", "cumin", "cupid",
"cuppa", "curbs", "curds", "cured", "cures", "curia", "curio", "curls", "curly", "curry", "curse", "curve", "curvy", "cushy", "cusps", "cuter", "cutie", "cutis", "cutup", "cycad", "cycle", "cyclo", "cynic",
"cysts", "czars", "dacha", "daddy", "dados", "daffy", "daily", "dairy", "daisy", "dales", "dames", "damns", "damps", "dance", "dandy", "dared", "dares", "darks", "darns", "darts", "dashi", "dated", "dater",
"dates", "datum", "daubs", "daunt", "davit", "dawns", "dazed", "deals", "dealt", "deans", "dears", "deary", "death", "debit", "debts", "debug", "debut", "decaf", "decal", "decay", "decks", "decor", "decoy",
"decry", "deeds", "deems", "deeps", "deers", "defer", "deify", "deign", "deism", "deist", "deity", "dekes", "delay", "delft", "delis", "dells", "delta", "delve", "demon", "demos", "demur", "denim", "dense",
"dents", "depot", "depth", "derby", "desks", "deter", "detox", "deuce", "devil", "dewar", "dhikr", "dhows", "dials", "diary", "diced", "dices", "dicey", "dicky", "dicta", "diets", "digit", "diked", "dikes",
"dills", "dilly", "dimer", "dimes", "dimly", "dinar", "dined", "diner", "dines", "dingo", "dings", "dingy", "dinks", "dinky", "dinos", "diode", "dippy", "direr", "dirge", "dirty", "disco", "discs", "dishy",
"disks", "ditch", "ditsy", "ditto", "ditty", "ditzy", "divan", "divas", "dived", "diver", "dives", "divot", "divvy", "dizzy", "docks", "dodge", "dodgy", "dodos", "doers", "doffs", "doges", "doggy", "dogma",
"doing", "doled", "doles", "dolls", "dolly", "dolor", "dolts", "domed", "domes", "donee", "dongs", "donna", "donor", "donut", "dooms", "doomy", "doors", "doozy", "doped", "dopes", "dopey", "dorks", "dorky",
"dorms", "dosas", "dosed", "doses", "doted", "dotes", "dotty", "doubt", "dough", "doula", "douse", "doves", "dowdy", "dowel", "dower", "downs", "downy", "dowry", "dowse", "doyen", "dozed", "dozen", "dozer",
"dozes", "drabs", "draft", "drags", "drain", "drake", "drama", "drams", "drank", "drape", "drawl", "drawn", "draws", "drays", "dread", "dream", "dreck", "dregs", "dress", "dribs", "dried", "drier", "dries",
"drift", "drill", "drily", "drink", "drips", "drive", "droid", "droll", "drone", "drool", "droop", "drops", "dross", "drove", "drown", "drugs", "druid", "drums", "drunk", "drupe", "dryad", "dryer", "dryly",
"duals", "ducal", "ducat", "duchy", "ducks", "ducky", "ducts", "dudes", "duels", "duets", "duffs", "dukes", "dulls", "dully", "dulse", "dumbo", "dummy", "dumps", "dumpy", "dunce", "dunes", "dunks", "duomo",
"duped", "dupes", "dural", "durum", "dusks", "dusky", "dusts", "dusty", "dutch", "duvet", "dwarf", "dweeb", "dwell", "dwelt", "dyads", "dyers", "dying", "dykes", "eager", "eagle", "eared", "earls", "early",
"earns", "earth", "eased", "easel", "easer", "eases", "eaten", "eater", "eaves", "ebbed", "ebony", "ebook", "echos", "eclat", "edema", "edged", "edger", "edges", "edict", "edify", "edits", "eejit", "eerie",
"egged", "egret", "eider", "eidos", "eight", "eject", "ejido", "eland", "elbow", "elder", "elect", "elegy", "elide", "elite", "elope", "elude", "elute", "elven", "elves", "email", "embed", "ember", "emcee",
"emery", "emirs", "emits", "emote", "empty", "enact", "ended", "endow", "enema", "enemy", "enjoy", "ennui", "enoki", "enrol", "ensue", "enter", "entry", "envoy", "eosin", "epics", "epoch", "epoxy", "equal",
"equip", "erase", "erect", "ergot", "erode", "erred", "error", "erupt", "essay", "ether", "ethic", "ethos", "ethyl", "etude", "euros", "evade", "evens", "event", "every", "evict", "evils", "evoke", "ewers",
"exact", "exalt", "exams", "excel", "execs", "exert", "exile", "exist", "exits", "expat", "expel", "expos", "extol", "extra", "exude", "exult", "exurb", "eying", "eyrie", "fable", "faced", "facer", "faces",
"facet", "facia", "facts", "faded", "fader", "fades", "faery", "fails", "faint", "fairs", "fairy", "faith", "faked", "faker", "fakes", "fakie", "fakir", "falls", "famed", "fancy", "fangs", "fanny", "farce",
"fared", "fares", "farms", "farts", "fasts", "fatal", "fated", "fates", "fatso", "fatty", "fatwa", "fault", "fauna", "fauns", "favas", "faves", "favor", "fawns", "faxed", "faxes", "fazed", "fazes", "fears",
"feast", "feats", "fecal", "feces", "feeds", "feels", "feign", "feint", "fella", "fells", "felon", "felts", "femme", "femur", "fence", "fends", "feral", "feria", "ferns", "ferny", "ferry", "fests", "fetal",
"fetch", "feted", "fetes", "fetid", "fetus", "feuds", "fever", "fewer", "fiats", "fiber", "fibre", "fiche", "ficus", "fiefs", "field", "fiend", "fiery", "fifes", "fifth", "fifty", "fight", "filch", "filed",
"filer", "files", "filet", "fills", "filly", "films", "filmy", "filth", "final", "finca", "finch", "finds", "fined", "finer", "fines", "finis", "finks", "fiord", "fired", "fires", "firms", "first", "fishy",
"fists", "fitly", "fiver", "fives", "fixed", "fixer", "fixes", "fizzy", "fjord", "flack", "flags", "flail", "flair", "flake", "flaky", "flame", "flank", "flans", "flaps", "flare", "flash", "flask", "flats",
"flaws", "flays", "fleas", "fleck", "flees", "fleet", "flesh", "flick", "flier", "flies", "fling", "float", "flood", "floor", "flour", "flown", "flows", "fluid", "flyer", "focal", "focus", "folks", "fonts",
"foods", "force", "forms", "forth", "forty", "forum", "found", "frame", "fraud", "fresh", "fried", "fries", "front", "frost", "fruit", "fuels", "fully", "funds", "funny", "gains", "games", "gamma", "gases",
"gates", "gauge", "gears", "genes", "genre", "ghost", "giant", "gifts", "girls", "given", "gives", "gland", "glass", "globe", "glory", "gloss", "glove", "glued", "goals", "goats", "going", "goods", "grace",
"grade", "grain", "grams", "grand", "grant", "grape", "graph", "grasp", "grass", "grave", "great", "greek", "green", "greet", "grief", "grill", "grind", "grips", "gross", "group", "grove", "grown", "grows",
"guard", "guess", "guest", "guide", "guild", "guilt", "habit", "hairs", "halls", "hands", "handy", "hangs", "happy", "harsh", "hated", "hates", "haven", "hawks", "heads", "heard", "heart", "heavy", "hedge",
"heels", "hello", "helps", "hence", "herbs", "highs", "hills", "hints", "hired", "hobby", "holds", "holes", "holly", "homes", "honey", "honor", "hooks", "hoped", "hopes", "horns", "horse", "hosts", "hotel",
"hours", "house", "hover", "human", "humor", "hurts", "icons", "ideal", "ideas", "idiot", "image", "imply", "inbox", "incur", "index", "indie", "inner", "input", "intro", "issue", "items", "jeans", "jelly",
"jewel", "joins", "joint", "jokes", "judge", "juice", "juicy", "jumps", "keeps", "kicks", "kills", "kinda", "kinds", "kings", "knees", "knife", "knock", "knots", "known", "knows", "label", "labor", "lacks",
"lakes", "lamps", "lands", "lanes", "large", "laser", "lasts", "later", "laugh", "layer", "leads", "leaks", "learn", "lease", "least", "leave", "legal", "lemon", "level", "lever", "light", "liked", "likes",
"limbs", "limit", "lined", "linen", "liner", "lines", "links", "lions", "lists", "lived", "liver", "lives", "loads", "loans", "lobby", "local", "locks", "lodge", "logic", "logos", "looks", "loops", "loose",
"lords", "loses", "loved", "lover", "loves", "lower", "loyal", "lucky", "lunar", "lunch", "lungs", "lying", "macro", "magic", "major", "maker", "makes", "males", "maple", "march", "marks", "marry", "masks",
"match", "mates", "maths", "matte", "maybe", "mayor", "meals", "means", "meant", "meats", "medal", "media", "meets", "melee", "menus", "mercy", "merge", "merit", "merry", "messy", "metal", "meter", "metro",
"micro", "midst", "might", "miles", "minds", "mines", "minor", "minus", "mixed", "mixer", "mixes", "model", "modem", "modes", "moist", "money", "month", "moral", "motor", "mount", "mouse", "mouth", "moved",
"moves", "movie", "music", "myths", "nails", "naked", "named", "names", "nasal", "nasty", "naval", "needs", "nerve", "never", "newer", "newly", "nexus", "nicer", "niche", "night", "ninja", "ninth", "noble",
"nodes", "noise", "noisy", "norms", "north", "notch", "noted", "notes", "novel", "nurse", "nylon", "oasis", "occur", "ocean", "offer", "often", "older", "olive", "omega", "onion", "onset", "opens", "opera",
"opted", "optic", "orbit", "order", "organ", "other", "ought", "ounce", "outer", "owned", "owner", "oxide", "packs", "pages", "pains", "paint", "pairs", "panel", "panic", "pants", "paper", "parks", "parts",
"party", "pasta", "paste", "patch", "paths", "patio", "pause", "peace", "peach", "peaks", "pearl", "pedal", "peers", "penis", "penny", "perks", "pests", "petty", "phase", "phone", "photo", "piano", "picks",
"piece", "piles", "pills", "pilot", "pinch", "pipes", "pitch", "pixel", "pizza", "place", "plain", "plane", "plans", "plant", "plate", "plays", "plaza", "plots", "plugs", "poems", "point", "poker", "polar",
"poles", "polls", "pools", "porch", "pores", "ports", "posed", "poses", "posts", "pouch", "pound", "power", "press", "price", "pride", "prime", "print", "prior", "prize", "probe", "promo", "prone", "proof",
"props", "proud", "prove", "proxy", "psalm", "pulls", "pulse", "pumps", "punch", "pupil", "puppy", "purse", "queen", "query", "quest", "queue", "quick", "quiet", "quilt", "quite", "quote", "races", "racks",
"radar", "radio", "rails", "rainy", "raise", "rally", "ranch", "range", "ranks", "rapid", "rated", "rates", "ratio", "razor", "reach", "react", "reads", "ready", "realm", "rebel", "refer", "reign", "relax",
"relay", "renal", "renew", "reply", "reset", "resin", "retro", "rider", "rides", "ridge", "rifle", "right", "rigid", "rings", "rinse", "risen", "rises", "risks", "risky", "rival", "river", "roads", "robot",
"rocks", "rocky", "rogue", "roles", "rolls", "roman", "rooms", "roots", "ropes", "roses", "rough", "round", "route", "royal", "rugby", "ruins", "ruled", "ruler", "rules", "rural", "sadly", "safer", "salad",
"sales", "salon", "sandy", "satin", "sauce", "saved", "saves", "scale", "scalp", "scans", "scare", "scarf", "scary", "scene", "scent", "scoop", "scope", "score", "scout", "scrap", "screw", "seals", "seams",
"seats", "seeds", "seeks", "seems", "sells", "sends", "sense", "serum", "serve", "setup", "seven", "sewer", "shade", "shaft", "shake", "shall", "shame", "shape", "share", "shark", "sharp", "sheep", "sheer",
"sheet", "shelf", "shell", "shift", "shine", "shiny", "ships", "shirt", "shock", "shoes", "shook", "shoot", "shops", "shore", "short", "shots", "shown", "shows", "sides", "siege", "sight", "sigma", "signs",
"silly", "since", "sites", "sixth", "sized", "sizes", "skies", "skill", "skins", "skirt", "skull", "slate", "slave", "sleek", "sleep", "slept", "slice", "slide", "slope", "slots", "small", "smart", "smell",
"smile", "smoke", "snack", "snake", "sneak", "socks", "soils", "solar", "solid", "solve", "songs", "sonic", "sorry", "sorts", "souls", "sound", "south", "space", "spare", "spark", "speak", "specs", "speed",
"spell", "spend", "spent", "sperm", "spice", "spicy", "spike", "spine", "spite", "split", "spoke", "spoon", "sport", "spots", "spray", "spurs", "squad", "stack", "staff", "stage", "stain", "stake", "stamp",
"stand", "stark", "stars", "start", "state", "stats", "stays", "steak", "steal", "steam", "steel", "steep", "steer", "stems", "steps", "stick", "stiff", "still", "stock", "stole", "stone", "stood", "stool",
"stops", "store", "storm", "story", "stove", "strap", "straw", "strip", "stuck", "study", "stuff", "style", "sucks", "sugar", "suite", "suits", "sunny", "super", "surge", "sushi", "swear", "sweat", "sweet",
"swept", "swift", "swing", "swiss", "sword", "syrup", "table", "taken", "takes", "tales", "talks", "tanks", "tapes", "tasks", "taste", "tasty", "taxes", "teach", "teams", "tears", "teens", "teeth", "tells",
"tempo", "tends", "tenth", "tents", "terms", "tests", "texts", "thank", "theft", "their", "theme", "there", "these", "thick", "thief", "thigh", "thing", "think", "third", "those", "three", "threw", "throw",
"thumb", "tiger", "tight", "tiles", "timer", "times", "tired", "tires", "title", "toast", "today", "token", "tones", "tools", "tooth", "topic", "torch", "total", "touch", "tough", "tours", "towel", "tower",
"towns", "toxic", "trace", "track", "tract", "trade", "trail", "train", "trait", "trans", "traps", "trash", "treat", "trees", "trend", "trial", "tribe", "trick", "tried", "tries", "trips", "trout", "truck",
"truly", "trump", "trunk", "trust", "truth", "tubes", "tumor", "tuned", "tunes", "turbo", "turns", "tutor", "tweet", "twice", "twins", "twist", "types", "tyres", "ultra", "uncle", "under", "union", "unite",
"units", "unity", "until", "upper", "upset", "urban", "urged", "urine", "usage", "users", "using", "usual", "vague", "valid", "value", "valve", "vapor", "vault", "vegan", "veins", "vents", "venue", "verse",
"video", "views", "villa", "vinyl", "viral", "virus", "visas", "visit", "vital", "vivid", "vocal", "vodka", "voice", "volts", "voted", "voter", "votes", "wages", "wagon", "waist", "walks", "walls", "wants",
"warns", "waste", "watch", "water", "watts", "waves", "wears", "weeds", "weeks", "weigh", "weird", "wells", "welsh", "whale", "wheat", "wheel", "where", "which", "while", "white", "whole", "whose", "wider",
"widow", "width", "winds", "wines", "wings", "wiped", "wired", "wires", "witch", "wives", "woman", "women", "woods", "words", "works", "world", "worms", "worry", "worse", "worst", "worth", "would", "wound",
"wrath", "wrist", "write", "wrong", "wrote", "yacht", "yards", "years", "yeast", "yield", "young", "yours", "youth", "yummy", "zones" };



void restart() {
	
	std::string past_guess1[5] = {};
	std::string past_guess2[5] = {};
	std::string past_guess3[5] = {};
	std::string past_guess4[5] = {};
	std::string past_guess5[5] = {};
	std::string past_guess6[5] = {};
	std::string box_rects[60] = {};
	std::string guess[5] = {};
	std::vector<char> answer_list{};
	std::string answer{};
	int screen_width{ 1250 };
	int screen_height{ 700 };
	int cell{ 97 };
	int ticker{ 0 };
	int random_numberword{ 2 };
	int oneright{ 0 };
	int tworight{ 0 };
	int threeright{ 0 };
	int fourright{ 0 };
	int fiveright{ 0 };
	int sixright{ 0 };
	int sevenright{ 0 };
	int eightright{ 0 };
	int nineright{ 0 };
	int tenright{ 0 };
	int elevenright{ 0 };
	int twelveright{ 0 };
	int thirteenright{ 0 };
	int fourteenright{ 0 };
	int fifteenright{ 0 };
	int sixteenright{ 0 };
	int seventeenright{ 0 };
	int eighteenright{ 0 };
	int nineteenright{ 0 };
	int twentyright{ 0 };
	int twentyoneright{ 0 };
	int twentytworight{ 0 };
	int twentythreeright{ 0 };
	int twentyfourright{ 0 };
	int twentyfiveright{ 0 };
	int twentysixright{ 0 };
	int twentysevenright{ 0 };
	int twentyeightright{ 0 };
	int twentynineright{ 0 };
	int thirtyright{ 0 };
	int adone{ 0 };
	int bdone{ 0 };
	int cdone{ 0 };
	int ddone{ 0 };
	int edone{ 0 };
	int fdone{ 0 };
	int gdone{ 0 };
	int hdone{ 0 };
	int idone{ 0 };
	int jdone{ 0 };
	int kdone{ 0 };
	int ldone{ 0 };
	int mdone{ 0 };
	int ndone{ 0 };
	int odone{ 0 };
	int pdone{ 0 };
	int qdone{ 0 };
	int rdone{ 0 };
	int sdone{ 0 };
	int tdone{ 0 };
	int udone{ 0 };
	int vdone{ 0 };
	int wdone{ 0 };
	int xdone{ 0 };
	int ydone{ 0 };
	int zdone{ 0 };
	srand(time(NULL));
}
int main()
{

	srand(time(NULL));
	sf::Font font;
	if (!font.loadFromFile("program_font.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}


	
	sf::Text input_one;
	input_one.setFont(font);
	input_one.setCharacterSize(80);
	input_one.setFillColor(sf::Color(100,100,100));
	input_one.setOrigin(sf::Vector2f(input1[0],input1[1]));
	input_one.setLetterSpacing(spacing);
	
	sf::Text input_two;
	input_two.setFont(font);
	input_two.setCharacterSize(80);
	input_two.setFillColor(sf::Color(100, 100, 100));
	input_two.setOrigin(sf::Vector2f(input2[0], input2[1]));
	input_two.setLetterSpacing(spacing);
	
	sf::Text input_three;
	input_three.setFont(font);
	input_three.setCharacterSize(80);
	input_three.setFillColor(sf::Color(100, 100, 100));
	input_three.setOrigin(sf::Vector2f(input3[0] - 5, input3[1]));
	input_three.setLetterSpacing(spacing);
	
	sf::Text input_four;
	input_four.setFont(font);
	input_four.setCharacterSize(80);
	input_four.setFillColor(sf::Color(100, 100, 100));
	input_four.setOrigin(sf::Vector2f(input4[0] - 5, input4[1]));
	input_four.setLetterSpacing(spacing);
	
	sf::Text input_five;
	input_five.setFont(font);
	input_five.setCharacterSize(80);
	input_five.setFillColor(sf::Color(100, 100, 100));
	input_five.setOrigin(sf::Vector2f(input5[0] - 5, input5[1]));
	input_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_one_letter_one;
	past_guess_one_letter_one.setFont(font);
	past_guess_one_letter_one.setCharacterSize(80);
	past_guess_one_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_one_letter_one.setOrigin(sf::Vector2f(past_guess_one_first[0], past_guess_one_first[1]));
	past_guess_one_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_one_letter_two;
	past_guess_one_letter_two.setFont(font);
	past_guess_one_letter_two.setCharacterSize(80);
	past_guess_one_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_one_letter_two.setOrigin(sf::Vector2f(past_guess_one_second[0],past_guess_one_second[1]));
	past_guess_one_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_one_letter_three;
	past_guess_one_letter_three.setFont(font);
	past_guess_one_letter_three.setCharacterSize(80);
	past_guess_one_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_one_letter_three.setOrigin(sf::Vector2f(past_guess_one_third[0]+3,past_guess_one_third[1]));
	past_guess_one_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_one_letter_four;
	past_guess_one_letter_four.setFont(font);
	past_guess_one_letter_four.setCharacterSize(80);
	past_guess_one_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_one_letter_four.setOrigin(sf::Vector2f(past_guess_one_fourth[0] - 5,past_guess_one_fourth[1]));
	past_guess_one_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_one_letter_five;
	past_guess_one_letter_five.setFont(font);
	past_guess_one_letter_five.setCharacterSize(80);
	past_guess_one_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_one_letter_five.setOrigin(sf::Vector2f(past_guess_one_fifth[0] - 5,past_guess_one_fifth[1]));
	past_guess_one_letter_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_two_letter_one;
	past_guess_two_letter_one.setFont(font);
	past_guess_two_letter_one.setCharacterSize(80);
	past_guess_two_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_two_letter_one.setOrigin(sf::Vector2f(past_guess_two_first[0],past_guess_two_first[1]));
	past_guess_two_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_two_letter_two;
	past_guess_two_letter_two.setFont(font);
	past_guess_two_letter_two.setCharacterSize(80);
	past_guess_two_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_two_letter_two.setOrigin(sf::Vector2f(past_guess_two_second[0],past_guess_two_second[1]));
	past_guess_two_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_two_letter_three;
	past_guess_two_letter_three.setFont(font);
	past_guess_two_letter_three.setCharacterSize(80);
	past_guess_two_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_two_letter_three.setOrigin(sf::Vector2f(past_guess_two_third[0] - 5,past_guess_two_third[1]));
	past_guess_two_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_two_letter_four;
	past_guess_two_letter_four.setFont(font);
	past_guess_two_letter_four.setCharacterSize(80);
	past_guess_two_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_two_letter_four.setOrigin(sf::Vector2f(past_guess_two_fourth[0] - 5,past_guess_two_fourth[1]));
	past_guess_two_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_two_letter_five;
	past_guess_two_letter_five.setFont(font);
	past_guess_two_letter_five.setCharacterSize(80);
	past_guess_two_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_two_letter_five.setOrigin(sf::Vector2f(past_guess_two_fifth[0] - 5,past_guess_two_fifth[1]));
	past_guess_two_letter_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_three_letter_one;
	past_guess_three_letter_one.setFont(font);
	past_guess_three_letter_one.setCharacterSize(80);
	past_guess_three_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_three_letter_one.setOrigin(sf::Vector2f(past_guess_three_first[0],past_guess_three_first[1]));
	past_guess_three_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_three_letter_two;
	past_guess_three_letter_two.setFont(font);
	past_guess_three_letter_two.setCharacterSize(80);
	past_guess_three_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_three_letter_two.setOrigin(sf::Vector2f(past_guess_three_second[0],past_guess_three_second[1]));
	past_guess_three_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_three_letter_three;
	past_guess_three_letter_three.setFont(font);
	past_guess_three_letter_three.setCharacterSize(80);
	past_guess_three_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_three_letter_three.setOrigin(sf::Vector2f(past_guess_three_third[0] - 5,past_guess_three_third[1]));
	past_guess_three_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_three_letter_four;
	past_guess_three_letter_four.setFont(font);
	past_guess_three_letter_four.setCharacterSize(80);
	past_guess_three_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_three_letter_four.setOrigin(sf::Vector2f(past_guess_three_fourth[0] - 5,past_guess_three_fourth[1]));
	past_guess_three_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_three_letter_five;
	past_guess_three_letter_five.setFont(font);
	past_guess_three_letter_five.setCharacterSize(80);
	past_guess_three_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_three_letter_five.setOrigin(sf::Vector2f(past_guess_three_fifth[0] - 5,past_guess_three_fifth[1]));
	past_guess_three_letter_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_four_letter_one;
	past_guess_four_letter_one.setFont(font);
	past_guess_four_letter_one.setCharacterSize(80);
	past_guess_four_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_four_letter_one.setOrigin(sf::Vector2f(past_guess_four_first[0],past_guess_four_first[1]));
	past_guess_four_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_four_letter_two;
	past_guess_four_letter_two.setFont(font);
	past_guess_four_letter_two.setCharacterSize(80);
	past_guess_four_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_four_letter_two.setOrigin(sf::Vector2f(past_guess_four_second[0],past_guess_four_second[1]));
	past_guess_four_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_four_letter_three;
	past_guess_four_letter_three.setFont(font);
	past_guess_four_letter_three.setCharacterSize(80);
	past_guess_four_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_four_letter_three.setOrigin(sf::Vector2f(past_guess_four_third[0] - 5,past_guess_four_third[1]));
	past_guess_four_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_four_letter_four;
	past_guess_four_letter_four.setFont(font);
	past_guess_four_letter_four.setCharacterSize(80);
	past_guess_four_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_four_letter_four.setOrigin(sf::Vector2f(past_guess_four_fourth[0] - 5,past_guess_four_fourth[1]));
	past_guess_four_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_four_letter_five;
	past_guess_four_letter_five.setFont(font);
	past_guess_four_letter_five.setCharacterSize(80);
	past_guess_four_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_four_letter_five.setOrigin(sf::Vector2f(past_guess_four_fifth[0] - 5,past_guess_four_fifth[1]));
	past_guess_four_letter_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_five_letter_one;
	past_guess_five_letter_one.setFont(font);
	past_guess_five_letter_one.setCharacterSize(80);
	past_guess_five_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_five_letter_one.setOrigin(sf::Vector2f(past_guess_five_first[0],past_guess_five_first[1]));
	past_guess_five_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_five_letter_two;
	past_guess_five_letter_two.setFont(font);
	past_guess_five_letter_two.setCharacterSize(80);
	past_guess_five_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_five_letter_two.setOrigin(sf::Vector2f(past_guess_five_second[0],past_guess_five_second[1]));
	past_guess_five_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_five_letter_three;
	past_guess_five_letter_three.setFont(font);
	past_guess_five_letter_three.setCharacterSize(80);
	past_guess_five_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_five_letter_three.setOrigin(sf::Vector2f(past_guess_five_third[0] - 5,past_guess_five_third[1]));
	past_guess_five_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_five_letter_four;
	past_guess_five_letter_four.setFont(font);
	past_guess_five_letter_four.setCharacterSize(80);
	past_guess_five_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_five_letter_four.setOrigin(sf::Vector2f(past_guess_five_fourth[0] - 5,past_guess_five_fourth[1]));
	past_guess_five_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_five_letter_five;
	past_guess_five_letter_five.setFont(font);
	past_guess_five_letter_five.setCharacterSize(80);
	past_guess_five_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_five_letter_five.setOrigin(sf::Vector2f(past_guess_five_fifth[0] - 5,past_guess_five_fifth[1]));
	past_guess_five_letter_five.setLetterSpacing(spacing);
	
	sf::Text past_guess_six_letter_one;
	past_guess_six_letter_one.setFont(font);
	past_guess_six_letter_one.setCharacterSize(80);
	past_guess_six_letter_one.setFillColor(sf::Color(100, 100, 100));
	past_guess_six_letter_one.setOrigin(sf::Vector2f(past_guess_six_first[0],past_guess_six_first[1]));
	past_guess_six_letter_one.setLetterSpacing(spacing);
	
	sf::Text past_guess_six_letter_two;
	past_guess_six_letter_two.setFont(font);
	past_guess_six_letter_two.setCharacterSize(80);
	past_guess_six_letter_two.setFillColor(sf::Color(100, 100, 100));
	past_guess_six_letter_two.setOrigin(sf::Vector2f(past_guess_six_second[0],past_guess_six_second[1]));
	past_guess_six_letter_two.setLetterSpacing(spacing);
	
	sf::Text past_guess_six_letter_three;
	past_guess_six_letter_three.setFont(font);
	past_guess_six_letter_three.setCharacterSize(80);
	past_guess_six_letter_three.setFillColor(sf::Color(100, 100, 100));
	past_guess_six_letter_three.setOrigin(sf::Vector2f(past_guess_six_third[0] - 5,past_guess_six_third[1]));
	past_guess_six_letter_three.setLetterSpacing(spacing);
	
	sf::Text past_guess_six_letter_four;
	past_guess_six_letter_four.setFont(font);
	past_guess_six_letter_four.setCharacterSize(80);
	past_guess_six_letter_four.setFillColor(sf::Color(100, 100, 100));
	past_guess_six_letter_four.setOrigin(sf::Vector2f(past_guess_six_fourth[0] - 5,past_guess_six_fourth[1]));
	past_guess_six_letter_four.setLetterSpacing(spacing);
	
	sf::Text past_guess_six_letter_five;
	past_guess_six_letter_five.setFont(font);
	past_guess_six_letter_five.setCharacterSize(80);
	past_guess_six_letter_five.setFillColor(sf::Color(100, 100, 100));
	past_guess_six_letter_five.setOrigin(sf::Vector2f(past_guess_six_fifth[0] - 5,past_guess_six_fifth[1]));
	past_guess_six_letter_five.setLetterSpacing(spacing);
	
	std::vector<char> answer_list{};
	std::string answer{};
    int screen_width{ 1250 };
    int screen_height{ 700 };
    int cell{ 97 };
	int ticker{ 0 };
    int random_numberword{ 2 };
	int oneright{ 0 };
	int tworight{ 0 };
	int threeright{ 0 };
	int fourright{ 0 };
	int fiveright{ 0 };
	int sixright{ 0 };
	int sevenright{ 0 };
	int eightright{ 0 };
	int nineright{ 0 };
	int tenright{ 0 };
	int elevenright{ 0 };
	int twelveright{ 0 };
	int thirteenright{ 0 };
	int fourteenright{ 0 };
	int fifteenright{ 0 };
	int sixteenright{ 0 };
	int seventeenright{ 0 };
	int eighteenright{ 0 };
	int nineteenright{ 0 };
	int twentyright{ 0 };
	int twentyoneright{ 0 };
	int twentytworight{ 0 };
	int twentythreeright{ 0 };
	int twentyfourright{ 0 };
	int twentyfiveright{ 0 };
	int twentysixright{ 0 };
	int twentysevenright{ 0 };
	int twentyeightright{ 0 };
	int twentynineright{ 0 };
	int thirtyright{ 0 };
	int adone{ 0 };
	int bdone{ 0 };
	int cdone{ 0 };
	int ddone{ 0 };
	int edone{ 0 };
	int fdone{ 0 };
	int gdone{ 0 };
	int hdone{ 0 };
	int idone{ 0 };
	int jdone{ 0 };
	int kdone{ 0 };
	int ldone{ 0 };
	int mdone{ 0 };
	int ndone{ 0 };
	int odone{ 0 };
	int pdone{ 0 };
	int qdone{ 0 };
	int rdone{ 0 };
	int sdone{ 0 };
	int tdone{ 0 };
	int udone{ 0 };
	int vdone{ 0 };
	int wdone{ 0 };
	int xdone{ 0 };
	int ydone{ 0 };
	int zdone{ 0 };
	std::string wordso{ "*****" };
	
	
    #ifdef NDEBUG
        HWND hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);
    #endif
	
    //Window init
    //  sf::RenderWindow window(sf::VideoMode(1920, 1080), "TEST", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "BOReDLE", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    sf::Event ev;
    //Game loop
    while (window.isOpen())
    {
		
		
		
		int keysize{ 65 };
		sf::RectangleShape keyq(sf::Vector2f(cell - 45, cell - 45));
		keyq.setPosition(sf::Vector2f((keysize * 0 + 550), (keysize * 0 + 215)));
		keyq.setOutlineThickness(3);
		keyq.setOutlineColor(sf::Color(100,100,100));
		if (qdone == 0) {
			keyq.setFillColor(sf::Color::Transparent);
		}
		if (qdone == 1) {
			keyq.setFillColor(sf::Color(51,255,51));
		}
		if (qdone == 2) {
			keyq.setFillColor(sf::Color(255,255,51));
		}
		if (qdone == 3) {
			keyq.setFillColor(sf::Color(100,100,100));
		}

		sf::RectangleShape keyw(sf::Vector2f(cell - 45, cell - 45));
		keyw.setPosition(sf::Vector2f((keysize * 1 + 550), (keysize * 0 + 215)));
		keyw.setOutlineThickness(3);
		keyw.setOutlineColor(sf::Color(100,100,100));
		if (wdone == 0) {
			keyw.setFillColor(sf::Color::Transparent);
		}
		if (wdone == 1) {
			keyw.setFillColor(sf::Color(51,255,51));
		}
		if (wdone == 2) {
			keyw.setFillColor(sf::Color(255,255,51));
		}
		if (wdone == 3) {
			keyw.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keye(sf::Vector2f(cell - 45, cell - 45));
		keye.setPosition(sf::Vector2f((keysize * 2 + 550), (keysize * 0 + 215)));
		keye.setOutlineThickness(3);
		keye.setOutlineColor(sf::Color(100,100,100));
		if (edone == 0) {
			keye.setFillColor(sf::Color::Transparent);
		}
		if (edone == 1) {
			keye.setFillColor(sf::Color(51,255,51));
		}
		if (edone == 2) {
			keye.setFillColor(sf::Color(255,255,51));
		}
		if (edone == 3) {
			keye.setFillColor(sf::Color(100, 100, 100));
		}
		

		sf::RectangleShape keyr(sf::Vector2f(cell - 45, cell - 45));
		keyr.setPosition(sf::Vector2f((keysize * 3 + 550), (keysize * 0 + 215)));
		keyr.setOutlineThickness(3);
		keyr.setOutlineColor(sf::Color(100,100,100));
		if (rdone == 0) {
			keyr.setFillColor(sf::Color::Transparent);
		}
		if (rdone == 1) {
			keyr.setFillColor(sf::Color(51,255,51));
		}
		if (rdone == 2) {
			keyr.setFillColor(sf::Color(255,255,51));
		}
		if (rdone == 3) {
			keyr.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyt(sf::Vector2f(cell - 45, cell - 45));
		keyt.setPosition(sf::Vector2f((keysize * 4 + 550), (keysize * 0 + 215)));
		keyt.setOutlineThickness(3);
		keyt.setOutlineColor(sf::Color(100,100,100));
		if (tdone == 0) {
			keyt.setFillColor(sf::Color::Transparent);
		}
		if (tdone == 1) {
			keyt.setFillColor(sf::Color(51,255,51));
		}
		if (tdone == 2) {
			keyt.setFillColor(sf::Color(255,255,51));
		}
		if (tdone == 3) {
			keyt.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyy(sf::Vector2f(cell - 45, cell - 45));
		keyy.setPosition(sf::Vector2f((keysize * 5 + 550), (keysize * 0 + 215)));
		keyy.setOutlineThickness(3);
		keyy.setOutlineColor(sf::Color(100,100,100));
		if (ydone == 0) {
			keyy.setFillColor(sf::Color::Transparent);
		}
		if (ydone == 1) {
			keyy.setFillColor(sf::Color(51,255,51));
		}
		if (ydone == 2) {
			keyy.setFillColor(sf::Color(255,255,51));
		}
		if (ydone == 3) {
			keyy.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyu(sf::Vector2f(cell - 45, cell - 45));
		keyu.setPosition(sf::Vector2f((keysize * 6 + 550), (keysize * 0 + 215)));
		keyu.setOutlineThickness(3);
		keyu.setOutlineColor(sf::Color(100,100,100));
		if (udone == 0) {
			keyu.setFillColor(sf::Color::Transparent);
		}
		if (udone == 1) {
			keyu.setFillColor(sf::Color(51,255,51));
		}
		if (udone == 2) {
			keyu.setFillColor(sf::Color(255,255,51));
		}
		if (udone == 3) {
			keyu.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyi(sf::Vector2f(cell - 45, cell - 45));
		keyi.setPosition(sf::Vector2f((keysize * 7 + 550), (keysize * 0 + 215)));
		keyi.setOutlineThickness(3);
		keyi.setOutlineColor(sf::Color(100,100,100));
		if (idone == 0) {
			keyi.setFillColor(sf::Color::Transparent);
		}
		if (idone == 1) {
			keyi.setFillColor(sf::Color(51,255,51));
		}
		if (idone == 2) {
			keyi.setFillColor(sf::Color(255,255,51));
		}
		if (idone == 3) {
			keyi.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyo(sf::Vector2f(cell - 45, cell - 45));
		keyo.setPosition(sf::Vector2f((keysize * 8 + 550), (keysize * 0 + 215)));
		keyo.setOutlineThickness(3);
		keyo.setOutlineColor(sf::Color(100,100,100));
		if (odone == 0) {
			keyo.setFillColor(sf::Color::Transparent);
		}
		if (odone == 1) {
			keyo.setFillColor(sf::Color(51,255,51));
		}
		if (odone == 2) {
			keyo.setFillColor(sf::Color(255,255,51));
		}
		if (odone == 3) {
			keyo.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyp(sf::Vector2f(cell - 45, cell - 45));
		keyp.setPosition(sf::Vector2f((keysize * 9 + 550), (keysize * 0 + 215)));
		keyp.setOutlineThickness(3);
		keyp.setOutlineColor(sf::Color(100,100,100));
		if (pdone == 0) {
			keyp.setFillColor(sf::Color::Transparent);
		}
		if (pdone == 1) {
			keyp.setFillColor(sf::Color(51,255,51));
		}
		if (pdone == 2) {
			keyp.setFillColor(sf::Color(255,255,51));
		}
		if (pdone == 3) {
			keyp.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keya(sf::Vector2f(cell - 45, cell - 45));
		keya.setPosition(sf::Vector2f((keysize * 0 + 580), (keysize * 1 + 215)));
		keya.setOutlineThickness(3);
		keya.setOutlineColor(sf::Color(100,100,100));
		if (adone == 0) {
			keya.setFillColor(sf::Color::Transparent);
		}
		if (adone == 1) {
			keya.setFillColor(sf::Color(51,255,51));
		}
		if (adone == 2) {
			keya.setFillColor(sf::Color(255,255,51));
		}
		if (adone == 3) {
			keya.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keys(sf::Vector2f(cell - 45, cell - 45));
		keys.setPosition(sf::Vector2f((keysize * 1 + 580), (keysize * 1 + 215)));
		keys.setOutlineThickness(3);
		keys.setOutlineColor(sf::Color(100,100,100));
		if (sdone == 0) {
			keys.setFillColor(sf::Color::Transparent);
		}
		if (sdone == 1) {
			keys.setFillColor(sf::Color(51,255,51));
		}
		if (sdone == 2) {
			keys.setFillColor(sf::Color(255,255,51));
		}
		if (sdone == 3) {
			keys.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyd(sf::Vector2f(cell - 45, cell - 45));
		keyd.setPosition(sf::Vector2f((keysize * 2 + 580), (keysize * 1 + 215)));
		keyd.setOutlineThickness(3);
		keyd.setOutlineColor(sf::Color(100,100,100));
		if (ddone == 0) {
			keyd.setFillColor(sf::Color::Transparent);
		}
		if (ddone == 1) {
			keyd.setFillColor(sf::Color(51,255,51));
		}
		if (ddone == 2) {
			keyd.setFillColor(sf::Color(255,255,51));
		}
		if (ddone == 3) {
			keyd.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyf(sf::Vector2f(cell - 45, cell - 45));
		keyf.setPosition(sf::Vector2f((keysize * 3 + 580), (keysize * 1 + 215)));
		keyf.setOutlineThickness(3);
		keyf.setOutlineColor(sf::Color(100,100,100));
		if (fdone == 0) {
			keyf.setFillColor(sf::Color::Transparent);
		}
		if (fdone == 1) {
			keyf.setFillColor(sf::Color(51,255,51));
		}
		if (fdone == 2) {
			keyf.setFillColor(sf::Color(255,255,51));
		}
		if (fdone == 3) {
			keyf.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyg(sf::Vector2f(cell - 45, cell - 45));
		keyg.setPosition(sf::Vector2f((keysize * 4 + 580), (keysize * 1 + 215)));
		keyg.setOutlineThickness(3);
		keyg.setOutlineColor(sf::Color(100,100,100));
		if (gdone == 0) {
			keyg.setFillColor(sf::Color::Transparent);
		}
		if (gdone == 1) {
			keyg.setFillColor(sf::Color(51,255,51));
		}
		if (gdone == 2) {
			keyg.setFillColor(sf::Color(255,255,51));
		}
		if (gdone == 3) {
			keyg.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyh(sf::Vector2f(cell - 45, cell - 45));
		keyh.setPosition(sf::Vector2f((keysize * 5 + 580), (keysize * 1 + 215)));
		keyh.setOutlineThickness(3);
		keyh.setOutlineColor(sf::Color(100,100,100));
		if (hdone == 0) {
			keyh.setFillColor(sf::Color::Transparent);
		}
		if (hdone == 1) {
			keyh.setFillColor(sf::Color(51,255,51));
		}
		if (hdone == 2) {
			keyh.setFillColor(sf::Color(255,255,51));
		}
		if (hdone == 3) {
			keyh.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyj(sf::Vector2f(cell - 45, cell - 45));
		keyj.setPosition(sf::Vector2f((keysize * 6 + 580), (keysize * 1 + 215)));
		keyj.setOutlineThickness(3);
		keyj.setOutlineColor(sf::Color(100,100,100));
		if (jdone == 0) {
			keyj.setFillColor(sf::Color::Transparent);
		}
		if (jdone == 1) {
			keyj.setFillColor(sf::Color(51,255,51));
		}
		if (jdone == 2) {
			keyj.setFillColor(sf::Color(255,255,51));
		}
		if (jdone == 3) {
			keyj.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyk(sf::Vector2f(cell - 45, cell - 45));
		keyk.setPosition(sf::Vector2f((keysize * 7 + 580), (keysize * 1 + 215)));
		keyk.setOutlineThickness(3);
		keyk.setOutlineColor(sf::Color(100,100,100));
		if (kdone == 0) {
			keyk.setFillColor(sf::Color::Transparent);
		}
		if (kdone == 1) {
			keyk.setFillColor(sf::Color(51,255,51));
		}
		if (kdone == 2) {
			keyk.setFillColor(sf::Color(255,255,51));
		}
		if (kdone == 3) {
			keyk.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyl(sf::Vector2f(cell - 45, cell - 45));
		keyl.setPosition(sf::Vector2f((keysize * 8 + 580), (keysize * 1 + 215)));
		keyl.setOutlineThickness(3);
		keyl.setOutlineColor(sf::Color(100,100,100));
		if (ldone == 0) {
			keyl.setFillColor(sf::Color::Transparent);
		}
		if (ldone == 1) {
			keyl.setFillColor(sf::Color(51,255,51));
		}
		if (ldone == 2) {
			keyl.setFillColor(sf::Color(255,255,51));
		}
		if (ldone == 3) {
			keyl.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyz(sf::Vector2f(cell - 45, cell - 45));
		keyz.setPosition(sf::Vector2f((keysize * 0 + 610), (keysize * 2 + 215)));
		keyz.setOutlineThickness(3);
		keyz.setOutlineColor(sf::Color(100,100,100));
		if (zdone == 0) {
			keyz.setFillColor(sf::Color::Transparent);
		}
		if (zdone == 1) {
			keyz.setFillColor(sf::Color(51,255,51));
		}
		if (zdone == 2) {
			keyz.setFillColor(sf::Color(255,255,51));
		}
		if (zdone == 3) {
			keyz.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyx(sf::Vector2f(cell - 45, cell - 45));
		keyx.setPosition(sf::Vector2f((keysize * 1 + 610), (keysize * 2 + 215)));
		keyx.setOutlineThickness(3);
		keyx.setOutlineColor(sf::Color(100,100,100));
		if (xdone == 0) {
			keyx.setFillColor(sf::Color::Transparent);
		}
		if (xdone == 1) {
			keyx.setFillColor(sf::Color(51,255,51));
		}
		if (xdone == 2) {
			keyx.setFillColor(sf::Color(255,255,51));
		}
		if (xdone == 3) {
			keyx.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyc(sf::Vector2f(cell - 45, cell - 45));
		keyc.setPosition(sf::Vector2f((keysize * 2 + 610), (keysize * 2 + 215)));
		keyc.setOutlineThickness(3);
		keyc.setOutlineColor(sf::Color(100,100,100));
		if (cdone == 0) {
			keyc.setFillColor(sf::Color::Transparent);
		}
		if (cdone == 1) {
			keyc.setFillColor(sf::Color(51,255,51));
		}
		if (cdone == 2) {
			keyc.setFillColor(sf::Color(255,255,51));
		}
		if (cdone == 3) {
			keyc.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyv(sf::Vector2f(cell - 45, cell - 45));
		keyv.setPosition(sf::Vector2f((keysize * 3 + 610), (keysize * 2 + 215)));
		keyv.setOutlineThickness(3);
		keyv.setOutlineColor(sf::Color(100,100,100));
		if (vdone == 0) {
			keyv.setFillColor(sf::Color::Transparent);
		}
		if (vdone == 1) {
			keyv.setFillColor(sf::Color(51,255,51));
		}
		if (vdone == 2) {
			keyv.setFillColor(sf::Color(255,255,51));
		}
		if (vdone == 3) {
			keyv.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyb(sf::Vector2f(cell - 45, cell - 45));
		keyb.setPosition(sf::Vector2f((keysize * 4 + 610), (keysize * 2 + 215)));
		keyb.setOutlineThickness(3);
		keyb.setOutlineColor(sf::Color(100,100,100));
		if (bdone == 0) {
			keyb.setFillColor(sf::Color::Transparent);
		}
		if (bdone == 1) {
			keyb.setFillColor(sf::Color(51,255,51));
		}
		if (bdone == 2) {
			keyb.setFillColor(sf::Color(255,255,51));
		}
		if (bdone == 3) {
			keyb.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keyn(sf::Vector2f(cell - 45, cell - 45));
		keyn.setPosition(sf::Vector2f((keysize * 5 + 610), (keysize * 2 + 215)));
		keyn.setOutlineThickness(3);
		keyn.setOutlineColor(sf::Color(100,100,100));
		if (ndone == 0) {
			keyn.setFillColor(sf::Color::Transparent);
		}
		if (ndone == 1) {
			keyn.setFillColor(sf::Color(51,255,51));
		}
		if (ndone == 2) {
			keyn.setFillColor(sf::Color(255,255,51));
		}
		if (ndone == 3) {
			keyn.setFillColor(sf::Color(100, 100, 100));
		}

		sf::RectangleShape keym(sf::Vector2f(cell - 45, cell - 45));
		keym.setPosition(sf::Vector2f((keysize * 6 + 610), (keysize * 2 + 215)));
		keym.setOutlineThickness(3);
		keym.setOutlineColor(sf::Color(100,100,100));
		if (mdone == 0) {
			keym.setFillColor(sf::Color::Transparent);
		}
		if (mdone == 1) {
			keym.setFillColor(sf::Color(51,255,51));
		}
		if (mdone == 2) {
			keym.setFillColor(sf::Color(255,255,51));
		}
		if (mdone == 3) {
			keym.setFillColor(sf::Color(100, 100, 100));
		}
		
		
		
		
		
		
		sf::RectangleShape rectangle00(sf::Vector2f(cell - 15, cell - 15));
		rectangle00.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 0 + 15)));
		rectangle00.setOutlineThickness(3);
		rectangle00.setOutlineColor(sf::Color(100,100,100));
		if (oneright == 0) 
			rectangle00.setFillColor(sf::Color::Transparent);
		
		else if (oneright == 2) 
			rectangle00.setFillColor(sf::Color(255,255,51));
		
		else
			rectangle00.setFillColor(sf::Color(51,255,51));
		

		sf::RectangleShape rectangle01(sf::Vector2f(cell - 15, cell - 15));
		rectangle01.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 0 + 15)));
		rectangle01.setOutlineThickness(3);
		rectangle01.setOutlineColor(sf::Color(100,100,100));
		if (tworight ==0) 
			rectangle01.setFillColor(sf::Color::Transparent);
		
		else if (tworight == 2) 
			rectangle01.setFillColor(sf::Color(255,255,51));
		
		else 
			rectangle01.setFillColor(sf::Color(51,255,51));
		

		sf::RectangleShape rectangle02(sf::Vector2f(cell - 15, cell - 15));
		rectangle02.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 0 + 15)));
		rectangle02.setOutlineThickness(3);
		rectangle02.setOutlineColor(sf::Color(100,100,100));
		if (threeright == 0)
			rectangle02.setFillColor(sf::Color::Transparent);
		
		else if (threeright == 2) 
			rectangle02.setFillColor(sf::Color(255,255,51));
		
		else 
			rectangle02.setFillColor(sf::Color(51,255,51));
		

		sf::RectangleShape rectangle03(sf::Vector2f(cell - 15, cell - 15));
		rectangle03.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 0 + 15)));
		rectangle03.setOutlineThickness(3);
		rectangle03.setOutlineColor(sf::Color(100,100,100));
		if (fourright == 0) 
			rectangle03.setFillColor(sf::Color::Transparent);
		
		else if (fourright == 2) 
			rectangle03.setFillColor(sf::Color(255,255,51));
		
		else 
			rectangle03.setFillColor(sf::Color(51,255,51));
		

		sf::RectangleShape rectangle04(sf::Vector2f(cell - 15, cell - 15));
		rectangle04.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 0 + 15)));
		rectangle04.setOutlineThickness(3);
		rectangle04.setOutlineColor(sf::Color(100,100,100));
		if (fiveright == 0) 
			rectangle04.setFillColor(sf::Color::Transparent);
		
		else if (fiveright == 2) 
			rectangle04.setFillColor(sf::Color(255,255,51));
		
		else 
			rectangle04.setFillColor(sf::Color(51,255,51));
		

		sf::RectangleShape rectangle10(sf::Vector2f(cell - 15, cell - 15));
		rectangle10.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 1 + 15)));
		rectangle10.setOutlineThickness(3);
		rectangle10.setOutlineColor(sf::Color(100,100,100));
		if (sixright == 0) {
			rectangle10.setFillColor(sf::Color::Transparent);
		}
		else if (sixright == 2) {
			rectangle10.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle10.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle11(sf::Vector2f(cell - 15, cell - 15));
		rectangle11.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 1 + 15)));
		rectangle11.setOutlineThickness(3);
		rectangle11.setOutlineColor(sf::Color(100,100,100));
		if (sevenright == 0) {
			rectangle11.setFillColor(sf::Color::Transparent);
		}
		else if (sevenright == 2) {
			rectangle11.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle11.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle12(sf::Vector2f(cell - 15, cell - 15));
		rectangle12.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 1 + 15)));
		rectangle12.setOutlineThickness(3);
		rectangle12.setOutlineColor(sf::Color(100,100,100));
		if (eightright == 0) {
			rectangle12.setFillColor(sf::Color::Transparent);
		}
		else if (eightright == 2) {
			rectangle12.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle12.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle13(sf::Vector2f(cell - 15, cell - 15));
		rectangle13.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 1 + 15)));
		rectangle13.setOutlineThickness(3);
		rectangle13.setOutlineColor(sf::Color(100,100,100));
		if (nineright == 0) {
			rectangle13.setFillColor(sf::Color::Transparent);
		}
		else if (nineright == 2) {
			rectangle13.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle13.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle14(sf::Vector2f(cell - 15, cell - 15));
		rectangle14.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 1 + 15)));
		rectangle14.setOutlineThickness(3);
		rectangle14.setOutlineColor(sf::Color(100,100,100));
		if (tenright == 0) {
			rectangle14.setFillColor(sf::Color::Transparent);
		}
		else if (tenright == 2) {
			rectangle14.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle14.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle20(sf::Vector2f(cell - 15, cell - 15));
		rectangle20.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 2 + 15)));
		rectangle20.setOutlineThickness(3);
		rectangle20.setOutlineColor(sf::Color(100,100,100));
		if (elevenright == 0) {
			rectangle20.setFillColor(sf::Color::Transparent);
		}
		else if (elevenright == 2) {
			rectangle20.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle20.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle21(sf::Vector2f(cell - 15, cell - 15));
		rectangle21.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 2 + 15)));
		rectangle21.setOutlineThickness(3);
		rectangle21.setOutlineColor(sf::Color(100,100,100));
		if (twelveright == 0) {
			rectangle21.setFillColor(sf::Color::Transparent);
		}
		else if (twelveright == 2) {
			rectangle21.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle21.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle22(sf::Vector2f(cell - 15, cell - 15));
		rectangle22.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 2 + 15)));
		rectangle22.setOutlineThickness(3);
		rectangle22.setOutlineColor(sf::Color(100,100,100));
		if (thirteenright == 0) {
			rectangle22.setFillColor(sf::Color::Transparent);
		}
		else if (thirteenright == 2) {
			rectangle22.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle22.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle23(sf::Vector2f(cell - 15, cell - 15));
		rectangle23.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 2 + 15)));
		rectangle23.setOutlineThickness(3);
		rectangle23.setOutlineColor(sf::Color(100,100,100));
		if (fourteenright == 0) {
			rectangle23.setFillColor(sf::Color::Transparent);
		}
		else if (fourteenright == 2) {
			rectangle23.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle23.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle24(sf::Vector2f(cell - 15, cell - 15));
		rectangle24.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 2 + 15)));
		rectangle24.setOutlineThickness(3);
		rectangle24.setOutlineColor(sf::Color(100,100,100));
		if (fifteenright == 0) {
			rectangle24.setFillColor(sf::Color::Transparent);
		}
		else if (fifteenright == 2) {
			rectangle24.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle24.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle30(sf::Vector2f(cell - 15, cell - 15));
		rectangle30.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 3 + 15)));
		rectangle30.setOutlineThickness(3);
		rectangle30.setOutlineColor(sf::Color(100,100,100));
		if (sixteenright == 0) {
			rectangle30.setFillColor(sf::Color::Transparent);
		}
		else if (sixteenright == 2) {
			rectangle30.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle30.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle31(sf::Vector2f(cell - 15, cell - 15));
		rectangle31.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 3 + 15)));
		rectangle31.setOutlineThickness(3);
		rectangle31.setOutlineColor(sf::Color(100,100,100));
		if (seventeenright == 0) {
			rectangle31.setFillColor(sf::Color::Transparent);
		}
		else if (seventeenright == 2) {
			rectangle31.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle31.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle32(sf::Vector2f(cell - 15, cell - 15));
		rectangle32.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 3 + 15)));
		rectangle32.setOutlineThickness(3);
		rectangle32.setOutlineColor(sf::Color(100,100,100));
		if (eighteenright == 0) {
			rectangle32.setFillColor(sf::Color::Transparent);
		}
		else if (eighteenright == 2) {
			rectangle32.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle32.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle33(sf::Vector2f(cell - 15, cell - 15));
		rectangle33.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 3 + 15)));
		rectangle33.setOutlineThickness(3);
		rectangle33.setOutlineColor(sf::Color(100,100,100));
		if (nineteenright == 0) {
			rectangle33.setFillColor(sf::Color::Transparent);
		}
		else if (nineteenright == 2) {
			rectangle33.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle33.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle34(sf::Vector2f(cell - 15, cell - 15));
		rectangle34.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 3 + 15)));
		rectangle34.setOutlineThickness(3);
		rectangle34.setOutlineColor(sf::Color(100,100,100));
		if (twentyright == 0) {
			rectangle34.setFillColor(sf::Color::Transparent);
		}
		else if (twentyright == 2) {
			rectangle34.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle34.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle40(sf::Vector2f(cell - 15, cell - 15));
		rectangle40.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 4 + 15)));
		rectangle40.setOutlineThickness(3);
		rectangle40.setOutlineColor(sf::Color(100,100,100));
		if (twentyoneright == 0) {
			rectangle40.setFillColor(sf::Color::Transparent);
		}
		else if (twentyoneright == 2) {
			rectangle40.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle40.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle41(sf::Vector2f(cell - 15, cell - 15));
		rectangle41.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 4 + 15)));
		rectangle41.setOutlineThickness(3);
		rectangle41.setOutlineColor(sf::Color(100,100,100));
		if (twentytworight == 0) {
			rectangle41.setFillColor(sf::Color::Transparent);
		}
		else if (twentytworight == 2) {
			rectangle41.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle41.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle42(sf::Vector2f(cell - 15, cell - 15));
		rectangle42.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 4 + 15)));
		rectangle42.setOutlineThickness(3);
		rectangle42.setOutlineColor(sf::Color(100,100,100));
		if (twentythreeright == 0) {
			rectangle42.setFillColor(sf::Color::Transparent);
		}
		else if (twentythreeright == 2) {
			rectangle42.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle42.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle43(sf::Vector2f(cell - 15, cell - 15));
		rectangle43.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 4 + 15)));
		rectangle43.setOutlineThickness(3);
		rectangle43.setOutlineColor(sf::Color(100,100,100));
		if (twentyfourright == 0) {
			rectangle43.setFillColor(sf::Color::Transparent);
		}
		else if (twentyfourright == 2) {
			rectangle43.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle43.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle44(sf::Vector2f(cell - 15, cell - 15));
		rectangle44.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 4 + 15)));
		rectangle44.setOutlineThickness(3); 
		rectangle44.setOutlineColor(sf::Color(100,100,100));
		if (twentyfiveright == 0) {
			rectangle44.setFillColor(sf::Color::Transparent);
		}
		else if (twentyfiveright == 2) {
			rectangle44.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle44.setFillColor(sf::Color(51,255,51));
		}
		
		sf::RectangleShape rectangle50(sf::Vector2f(cell - 15, cell - 15));
		rectangle50.setPosition(sf::Vector2f((cell * 0 + 15), (cell * 5 + 15)));
		rectangle50.setOutlineThickness(3);
		rectangle50.setOutlineColor(sf::Color(100,100,100));
		if (twentysixright == 0) {
			rectangle50.setFillColor(sf::Color::Transparent);
		}
		else if (twentysixright == 2) {
			rectangle50.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle50.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle51(sf::Vector2f(cell - 15, cell - 15));
		rectangle51.setPosition(sf::Vector2f((cell * 1 + 15), (cell * 5 + 15)));
		rectangle51.setOutlineThickness(3);
		rectangle51.setOutlineColor(sf::Color(100,100,100));
		if (twentysevenright == 0) {
			rectangle51.setFillColor(sf::Color::Transparent);
		}
		else if (twentysevenright == 2) {
			rectangle51.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle51.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle52(sf::Vector2f(cell - 15, cell - 15));
		rectangle52.setPosition(sf::Vector2f((cell * 2 + 15), (cell * 5 + 15)));
		rectangle52.setOutlineThickness(3);
		rectangle52.setOutlineColor(sf::Color(100,100,100));
		if (twentyeightright == 0) {
			rectangle52.setFillColor(sf::Color::Transparent);
		}
		else if (twentyeightright == 2) {
			rectangle52.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle52.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle53(sf::Vector2f(cell - 15, cell - 15));
		rectangle53.setPosition(sf::Vector2f((cell * 3 + 15), (cell * 5 + 15)));
		rectangle53.setOutlineThickness(3);
		rectangle53.setOutlineColor(sf::Color(100,100,100));
		if (twentynineright == 0) {
			rectangle53.setFillColor(sf::Color::Transparent);
		}
		else if (twentynineright == 2) {
			rectangle53.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle53.setFillColor(sf::Color(51,255,51));
		}

		sf::RectangleShape rectangle54(sf::Vector2f(cell - 15, cell - 15));
		rectangle54.setPosition(sf::Vector2f((cell * 4 + 15), (cell * 5 + 15)));
		rectangle54.setOutlineThickness(3);
		rectangle54.setOutlineColor(sf::Color(100,100,100));
		if (thirtyright == 0) {
			rectangle54.setFillColor(sf::Color::Transparent);
		}
		else if (thirtyright == 2) {
			rectangle54.setFillColor(sf::Color(255,255,51));
		}
		else {
			rectangle54.setFillColor(sf::Color(51,255,51));
		}
		if (ticker == 0)
		{
			enterflag = 0;
			random_numberword = (rand() % 567);
			answer = words_list[random_numberword];
			
			for (int i = 0; i < answer.length(); i++)
			{

				answer_list.push_back(tolower(answer[i]));
			}
			ticker = 1;
		}
		while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
				{
					ticker = 7;
					enterflag = 1;
				}
				if (ev.key.code == sf::Keyboard::A)
					if (guess->size() <= 4)
						guess->push_back('a');
				if (ev.key.code == sf::Keyboard::B)
					if (guess->size() <= 4)
						guess->push_back('b');
				if (ev.key.code == sf::Keyboard::C)
					if (guess->size() <= 4)
						guess->push_back('c');
				if (ev.key.code == sf::Keyboard::D)
					if (guess->size() <= 4)
						guess->push_back('d');
				if (ev.key.code == sf::Keyboard::E)
					if (guess->size() <= 4)
						guess->push_back('e');
				if (ev.key.code == sf::Keyboard::F)
					if (guess->size() <= 4)
						guess->push_back('f');
				if (ev.key.code == sf::Keyboard::G)
					if (guess->size() <= 4)
						guess->push_back('g');
				if (ev.key.code == sf::Keyboard::H)
					if (guess->size() <= 4)
						guess->push_back('h');
				if (ev.key.code == sf::Keyboard::I)
					if (guess->size() <= 4)
						guess->push_back('i');
				if (ev.key.code == sf::Keyboard::J)
					if (guess->size() <= 4)
						guess->push_back('j');
				if (ev.key.code == sf::Keyboard::K)
					if (guess->size() <= 4)
						guess->push_back('k');
				if (ev.key.code == sf::Keyboard::L)
					if (guess->size() <= 4)
						guess->push_back('l');
				if (ev.key.code == sf::Keyboard::M)
					if (guess->size() <= 4)
						guess->push_back('m');
				if (ev.key.code == sf::Keyboard::N)
					if (guess->size() <= 4)
						guess->push_back('n');
				if (ev.key.code == sf::Keyboard::O)
					if (guess->size() <= 4)
						guess->push_back('o');
				if (ev.key.code == sf::Keyboard::P)
					if (guess->size() <= 4)
						guess->push_back('p');
				if (ev.key.code == sf::Keyboard::Q)
					if (guess->size() <= 4)
						guess->push_back('q');
				if (ev.key.code == sf::Keyboard::R)
					if (guess->size() <= 4)
						guess->push_back('r');
				if (ev.key.code == sf::Keyboard::S)
					if (guess->size() <= 4)
						guess->push_back('s');
				if (ev.key.code == sf::Keyboard::T)
					if (guess->size() <= 4)
						guess->push_back('t');
				if (ev.key.code == sf::Keyboard::U)
					if (guess->size() <= 4)
						guess->push_back('u');
				if (ev.key.code == sf::Keyboard::V)
					if (guess->size() <= 4)
						guess->push_back('v');
				if (ev.key.code == sf::Keyboard::W)
					if (guess->size() <= 4)
						guess->push_back('w');
				if (ev.key.code == sf::Keyboard::X)
					if (guess->size() <= 4)
						guess->push_back('x');
				if (ev.key.code == sf::Keyboard::Y)
					if (guess->size() <= 4)
						guess->push_back('y');
				if (ev.key.code == sf::Keyboard::Z)
					if (guess->size() <= 4)
						guess->push_back('z');
				if (ev.key.code == sf::Keyboard::BackSpace)
					if (guess->size()>=1)
						guess->pop_back();
				if (ev.key.code == sf::Keyboard::Space)
					restart();
				if (ev.key.code == sf::Keyboard::Return)
				{
					string guess_full = guess[0] + guess[1] + guess[2] + guess[3] + guess[4];
					std::cout << guess_full << std::endl;
					char keyone{ answer_list.at(0) };
					char keytwo{ answer_list.at(1) };
					char keythree{ answer_list.at(2) };
					char keyfour{ answer_list.at(3) };
					char keyfive{ answer_list.at(4) };
					if (guess->size() >= 5 || ticker == 7)
					{
						
						if (find(dictionary_list.begin(), dictionary_list.end(), guess_full) != dictionary_list.end() || ticker == 6 || ticker == 7)
							
						{	
							if (ticker == 1)
							{
							

								past_guess1[0] = guess[0];
								past_guess1[1] = guess[1];
								past_guess1[2] = guess[2];
								past_guess1[3] = guess[3];
								past_guess1[4] = guess[4];
								guess->clear();
								std::cout << answer << std::endl << std::endl;

								char firstone{ past_guess1->at(0) };
								char secondone{ past_guess1->at(1) };
								char thirdone{ past_guess1->at(2) };
								char fourthone{ past_guess1->at(3) };
								char fifthone{ past_guess1->at(4) };
							
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								if (firstone == answer_list.at(0))
								{
									oneright = 1;
									if (firstone == 'a')
										adone = 1;
									if (firstone == 'b')
										bdone = 1;
									if (firstone == 'c')
										cdone = 1;
									if (firstone == 'd')
										ddone = 1;
									if (firstone == 'e')
										edone = 1;
									if (firstone == 'f')
										fdone = 1;
									if (firstone == 'g')
										gdone = 1;
									if (firstone == 'h')
										hdone = 1;
									if (firstone == 'i')
										idone = 1;
									if (firstone == 'j')
										jdone = 1;
									if (firstone == 'k')
										kdone = 1;
									if (firstone == 'l')
										ldone = 1;
									if (firstone == 'm')
										mdone = 1;
									if (firstone == 'n')
										ndone = 1;
									if (firstone == 'o')
										odone = 1;
									if (firstone == 'p')
										pdone = 1;
									if (firstone == 'q')
										qdone = 1;
									if (firstone == 'r')
										rdone = 1;
									if (firstone == 's')
										sdone = 1;
									if (firstone == 't')
										tdone = 1;
									if (firstone == 'u')
										udone = 1;
									if (firstone == 'v')
										vdone = 1;
									if (firstone == 'w')
										wdone = 1;
									if (firstone == 'x')
										xdone = 1;
									if (firstone == 'y')
										ydone = 1;
									if (firstone == 'z')
										zdone = 1;
								}
								else if (firstone == keyone || firstone == keytwo || firstone == keythree || firstone == keyfour || firstone == keyfive)
								{
									oneright = 2;
									if (firstone == 'a')
										adone = 2;
									if (firstone == 'b')
										bdone = 2;
									if (firstone == 'c')
										cdone = 2;
									if (firstone == 'd')
										ddone = 2;
									if (firstone == 'e')
										edone = 2;
									if (firstone == 'f')
										fdone = 2;
									if (firstone == 'g')
										gdone = 2;
									if (firstone == 'h')
										hdone = 2;
									if (firstone == 'i')
										idone = 2;
									if (firstone == 'j')
										jdone = 2;
									if (firstone == 'k')
										kdone = 2;
									if (firstone == 'l')
										ldone = 2;
									if (firstone == 'm')
										mdone = 2;
									if (firstone == 'n')
										ndone = 2;
									if (firstone == 'o')
										odone = 2;
									if (firstone == 'p')
										pdone = 2;
									if (firstone == 'q')
										qdone = 2;
									if (firstone == 'r')
										rdone = 2;
									if (firstone == 's')
										sdone = 2;
									if (firstone == 't')
										tdone = 2;
									if (firstone == 'u')
										udone = 2;
									if (firstone == 'v')
										vdone = 2;
									if (firstone == 'w')
										wdone = 2;
									if (firstone == 'x')
										xdone = 2;
									if (firstone == 'y')
										ydone = 2;
									if (firstone == 'z')
										zdone = 2;

								}
								else{
									oneright = 0;
								if (firstone == 'a')
									adone = 3;
								if (firstone == 'b')
									bdone = 3;
								if (firstone == 'c')
									cdone = 3;
								if (firstone == 'd')
									ddone = 3;
								if (firstone == 'e')
									edone = 3;
								if (firstone == 'f')
									fdone = 3;
								if (firstone == 'g')
									gdone = 3;
								if (firstone == 'h')
									hdone = 3;
								if (firstone == 'i')
									idone = 3;
								if (firstone == 'j')
									jdone = 3;
								if (firstone == 'k')
									kdone = 3;
								if (firstone == 'l')
									ldone = 3;
								if (firstone == 'm')
									mdone = 3;
								if (firstone == 'n')
									ndone = 3;
								if (firstone == 'o')
									odone = 3;
								if (firstone == 'p')
									pdone = 3;
								if (firstone == 'q')
									qdone = 3;
								if (firstone == 'r')
									rdone = 3;
								if (firstone == 's')
									sdone = 3;
								if (firstone == 't')
									tdone = 3;
								if (firstone == 'u')
									udone = 3;
								if (firstone == 'v')
									vdone = 3;
								if (firstone == 'w')
									wdone = 3;
								if (firstone == 'x')
									xdone = 3;
								if (firstone == 'y')
									ydone = 3;
								if (firstone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (secondone == answer_list.at(1))
								{
									tworight = 1;
									if (secondone == 'a')
										adone = 1;
									if (secondone == 'b')
										bdone = 1;
									if (secondone == 'c')
										cdone = 1;
									if (secondone == 'd')
										ddone = 1;
									if (secondone == 'e')
										edone = 1;
									if (secondone == 'f')
										fdone = 1;
									if (secondone == 'g')
										gdone = 1;
									if (secondone == 'h')
										hdone = 1;
									if (secondone == 'i')
										idone = 1;
									if (secondone == 'j')
										jdone = 1;
									if (secondone == 'k')
										kdone = 1;
									if (secondone == 'l')
										ldone = 1;
									if (secondone == 'm')
										mdone = 1;
									if (secondone == 'n')
										ndone = 1;
									if (secondone == 'o')
										odone = 1;
									if (secondone == 'p')
										pdone = 1;
									if (secondone == 'q')
										qdone = 1;
									if (secondone == 'r')
										rdone = 1;
									if (secondone == 's')
										sdone = 1;
									if (secondone == 't')
										tdone = 1;
									if (secondone == 'u')
										udone = 1;
									if (secondone == 'v')
										vdone = 1;
									if (secondone == 'w')
										wdone = 1;
									if (secondone == 'x')
										xdone = 1;
									if (secondone == 'y')
										ydone = 1;
									if (secondone == 'z')
										zdone = 1;
								
								}
								else if (secondone == keyone || secondone == keytwo || secondone == keythree || secondone == keyfour || secondone == keyfive)
								{
									tworight = 2;
									if (secondone == 'a')
										adone = 2;
									if (secondone == 'b')
										bdone = 2;
									if (secondone == 'c')
										cdone = 2;
									if (secondone == 'd')
										ddone = 2;
									if (secondone == 'e')
										edone = 2;
									if (secondone == 'f')
										fdone = 2;
									if (secondone == 'g')
										gdone = 2;
									if (secondone == 'h')
										hdone = 2;
									if (secondone == 'i')
										idone = 2;
									if (secondone == 'j')
										jdone = 2;
									if (secondone == 'k')
										kdone = 2;
									if (secondone == 'l')
										ldone = 2;
									if (secondone == 'm')
										mdone = 2;
									if (secondone == 'n')
										ndone = 2;
									if (secondone == 'o')
										odone = 2;
									if (secondone == 'p')
										pdone = 2;
									if (secondone == 'q')
										qdone = 2;
									if (secondone == 'r')
										rdone = 2;
									if (secondone == 's')
										sdone = 2;
									if (secondone == 't')
										tdone = 2;
									if (secondone == 'u')
										udone = 2;
									if (secondone == 'v')
										vdone = 2;
									if (secondone == 'w')
										wdone = 2;
									if (secondone == 'x')
										xdone = 2;
									if (secondone == 'y')
										ydone = 2;
									if (secondone == 'z')
										zdone = 2;

								}
								else{
									tworight = 0;
								if (secondone == 'a')
									adone = 3;
								if (secondone == 'b')
									bdone = 3;
								if (secondone == 'c')
									cdone = 3;
								if (secondone == 'd')
									ddone = 3;
								if (secondone == 'e')
									edone = 3;
								if (secondone == 'f')
									fdone = 3;
								if (secondone == 'g')
									gdone = 3;
								if (secondone == 'h')
									hdone = 3;
								if (secondone == 'i')
									idone = 3;
								if (secondone == 'j')
									jdone = 3;
								if (secondone == 'k')
									kdone = 3;
								if (secondone == 'l')
									ldone = 3;
								if (secondone == 'm')
									mdone = 3;
								if (secondone == 'n')
									ndone = 3;
								if (secondone == 'o')
									odone = 3;
								if (secondone == 'p')
									pdone = 3;
								if (secondone == 'q')
									qdone = 3;
								if (secondone == 'r')
									rdone = 3;
								if (secondone == 's')
									sdone = 3;
								if (secondone == 't')
									tdone = 3;
								if (secondone == 'u')
									udone = 3;
								if (secondone == 'v')
									vdone = 3;
								if (secondone == 'w')
									wdone = 3;
								if (secondone == 'x')
									xdone = 3;
								if (secondone == 'y')
									ydone = 3;
								if (secondone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (thirdone == answer_list.at(2))
								{
									threeright = 1;
									if (thirdone == 'a')
										adone = 1;
									if (thirdone == 'b')
										bdone = 1;
									if (thirdone == 'c')
										cdone = 1;
									if (thirdone == 'd')
										ddone = 1;
									if (thirdone == 'e')
										edone = 1;
									if (thirdone == 'f')
										fdone = 1;
									if (thirdone == 'g')
										gdone = 1;
									if (thirdone == 'h')
										hdone = 1;
									if (thirdone == 'i')
										idone = 1;
									if (thirdone == 'j')
										jdone = 1;
									if (thirdone == 'k')
										kdone = 1;
									if (thirdone == 'l')
										ldone = 1;
									if (thirdone == 'm')
										mdone = 1;
									if (thirdone == 'n')
										ndone = 1;
									if (thirdone == 'o')
										odone = 1;
									if (thirdone == 'p')
										pdone = 1;
									if (thirdone == 'q')
										qdone = 1;
									if (thirdone == 'r')
										rdone = 1;
									if (thirdone == 's')
										sdone = 1;
									if (thirdone == 't')
										tdone = 1;
									if (thirdone == 'u')
										udone = 1;
									if (thirdone == 'v')
										vdone = 1;
									if (thirdone == 'w')
										wdone = 1;
									if (thirdone == 'x')
										xdone = 1;
									if (thirdone == 'y')
										ydone = 1;
									if (thirdone == 'z')
										zdone = 1;
								}
								else if (thirdone == keyone || thirdone == keytwo || thirdone == keythree || thirdone == keyfour || thirdone == keyfive)
								{
									threeright = 2;
									if (thirdone == 'a')
										adone = 2;
									if (thirdone == 'b')
										bdone = 2;
									if (thirdone == 'c')
										cdone = 2;
									if (thirdone == 'd')
										ddone = 2;
									if (thirdone == 'e')
										edone = 2;
									if (thirdone == 'f')
										fdone = 2;
									if (thirdone == 'g')
										gdone = 2;
									if (thirdone == 'h')
										hdone = 2;
									if (thirdone == 'i')
										idone = 2;
									if (thirdone == 'j')
										jdone = 2;
									if (thirdone == 'k')
										kdone = 2;
									if (thirdone == 'l')
										ldone = 2;
									if (thirdone == 'm')
										mdone = 2;
									if (thirdone == 'n')
										ndone = 2;
									if (thirdone == 'o')
										odone = 2;
									if (thirdone == 'p')
										pdone = 2;
									if (thirdone == 'q')
										qdone = 2;
									if (thirdone == 'r')
										rdone = 2;
									if (thirdone == 's')
										sdone = 2;
									if (thirdone == 't')
										tdone = 2;
									if (thirdone == 'u')
										udone = 2;
									if (thirdone == 'v')
										vdone = 2;
									if (thirdone == 'w')
										wdone = 2;
									if (thirdone == 'x')
										xdone = 2;
									if (thirdone == 'y')
										ydone = 2;
									if (thirdone == 'z')
										zdone = 2;

								}
								else{
									threeright = 0;
								if (thirdone == 'a')
									adone = 3;
								if (thirdone == 'b')
									bdone = 3;
								if (thirdone == 'c')
									cdone = 3;
								if (thirdone == 'd')
									ddone = 3;
								if (thirdone == 'e')
									edone = 3;
								if (thirdone == 'f')
									fdone = 3;
								if (thirdone == 'g')
									gdone = 3;
								if (thirdone == 'h')
									hdone = 3;
								if (thirdone == 'i')
									idone = 3;
								if (thirdone == 'j')
									jdone = 3;
								if (thirdone == 'k')
									kdone = 3;
								if (thirdone == 'l')
									ldone = 3;
								if (thirdone == 'm')
									mdone = 3;
								if (thirdone == 'n')
									ndone = 3;
								if (thirdone == 'o')
									odone = 3;
								if (thirdone == 'p')
									pdone = 3;
								if (thirdone == 'q')
									qdone = 3;
								if (thirdone == 'r')
									rdone = 3;
								if (thirdone == 's')
									sdone = 3;
								if (thirdone == 't')
									tdone = 3;
								if (thirdone == 'u')
									udone = 3;
								if (thirdone == 'v')
									vdone = 3;
								if (thirdone == 'w')
									wdone = 3;
								if (thirdone == 'x')
									xdone = 3;
								if (thirdone == 'y')
									ydone = 3;
								if (thirdone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (fourthone == answer_list.at(3))
								{
									fourright = 1;
									if (fourthone == 'a')
										adone = 1;
									if (fourthone == 'b')
										bdone = 1;
									if (fourthone == 'c')
										cdone = 1;
									if (fourthone == 'd')
										ddone = 1;
									if (fourthone == 'e')
										edone = 1;
									if (fourthone == 'f')
										fdone = 1;
									if (fourthone == 'g')
										gdone = 1;
									if (fourthone == 'h')
										hdone = 1;
									if (fourthone == 'i')
										idone = 1;
									if (fourthone == 'j')
										jdone = 1;
									if (fourthone == 'k')
										kdone = 1;
									if (fourthone == 'l')
										ldone = 1;
									if (fourthone == 'm')
										mdone = 1;
									if (fourthone == 'n')
										ndone = 1;
									if (fourthone == 'o')
										odone = 1;
									if (fourthone == 'p')
										pdone = 1;
									if (fourthone == 'q')
										qdone = 1;
									if (fourthone == 'r')
										rdone = 1;
									if (fourthone == 's')
										sdone = 1;
									if (fourthone == 't')
										tdone = 1;
									if (fourthone == 'u')
										udone = 1;
									if (fourthone == 'v')
										vdone = 1;
									if (fourthone == 'w')
										wdone = 1;
									if (fourthone == 'x')
										xdone = 1;
									if (fourthone == 'y')
										ydone = 1;
									if (fourthone == 'z')
										zdone = 1;
								}
								else if (fourthone == keyone || fourthone == keytwo || fourthone == keythree || fourthone == keyfour || fourthone == keyfive)
								{
									fourright = 2;
									if (fourthone == 'a')
										adone = 2;
									if (fourthone == 'b')
										bdone = 2;
									if (fourthone == 'c')
										cdone = 2;
									if (fourthone == 'd')
										ddone = 2;
									if (fourthone == 'e')
										edone = 2;
									if (fourthone == 'f')
										fdone = 2;
									if (fourthone == 'g')
										gdone = 2;
									if (fourthone == 'h')
										hdone = 2;
									if (fourthone == 'i')
										idone = 2;
									if (fourthone == 'j')
										jdone = 2;
									if (fourthone == 'k')
										kdone = 2;
									if (fourthone == 'l')
										ldone = 2;
									if (fourthone == 'm')
										mdone = 2;
									if (fourthone == 'n')
										ndone = 2;
									if (fourthone == 'o')
										odone = 2;
									if (fourthone == 'p')
										pdone = 2;
									if (fourthone == 'q')
										qdone = 2;
									if (fourthone == 'r')
										rdone = 2;
									if (fourthone == 's')
										sdone = 2;
									if (fourthone == 't')
										tdone = 2;
									if (fourthone == 'u')
										udone = 2;
									if (fourthone == 'v')
										vdone = 2;
									if (fourthone == 'w')
										wdone = 2;
									if (fourthone == 'x')
										xdone = 2;
									if (fourthone == 'y')
										ydone = 2;
									if (fourthone == 'z')
										zdone = 2;

								}
								else{
									fourright = 0;
								if (fourthone == 'a')
									adone = 3;
								if (fourthone == 'b')
									bdone = 3;
								if (fourthone == 'c')
									cdone = 3;
								if (fourthone == 'd')
									ddone = 3;
								if (fourthone == 'e')
									edone = 3;
								if (fourthone == 'f')
									fdone = 3;
								if (fourthone == 'g')
									gdone = 3;
								if (fourthone == 'h')
									hdone = 3;
								if (fourthone == 'i')
									idone = 3;
								if (fourthone == 'j')
									jdone = 3;
								if (fourthone == 'k')
									kdone = 3;
								if (fourthone == 'l')
									ldone = 3;
								if (fourthone == 'm')
									mdone = 3;
								if (fourthone == 'n')
									ndone = 3;
								if (fourthone == 'o')
									odone = 3;
								if (fourthone == 'p')
									pdone = 3;
								if (fourthone == 'q')
									qdone = 3;
								if (fourthone == 'r')
									rdone = 3;
								if (fourthone == 's')
									sdone = 3;
								if (fourthone == 't')
									tdone = 3;
								if (fourthone == 'u')
									udone = 3;
								if (fourthone == 'v')
									vdone = 3;
								if (fourthone == 'w')
									wdone = 3;
								if (fourthone == 'x')
									xdone = 3;
								if (fourthone == 'y')
									ydone = 3;
								if (fourthone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (fifthone == answer_list.at(4))
								{
									fiveright = 1;
									if (fifthone == 'a')
										adone = 1;
									if (fifthone == 'b')
										bdone = 1;
									if (fifthone == 'c')
										cdone = 1;
									if (fifthone == 'd')
										ddone = 1;
									if (fifthone == 'e')
										edone = 1;
									if (fifthone == 'f')
										fdone = 1;
									if (fifthone == 'g')
										gdone = 1;
									if (fifthone == 'h')
										hdone = 1;
									if (fifthone == 'i')
										idone = 1;
									if (fifthone == 'j')
										jdone = 1;
									if (fifthone == 'k')
										kdone = 1;
									if (fifthone == 'l')
										ldone = 1;
									if (fifthone == 'm')
										mdone = 1;
									if (fifthone == 'n')
										ndone = 1;
									if (fifthone == 'o')
										odone = 1;
									if (fifthone == 'p')
										pdone = 1;
									if (fifthone == 'q')
										qdone = 1;
									if (fifthone == 'r')
										rdone = 1;
									if (fifthone == 's')
										sdone = 1;
									if (fifthone == 't')
										tdone = 1;
									if (fifthone == 'u')
										udone = 1;
									if (fifthone == 'v')
										vdone = 1;
									if (fifthone == 'w')
										wdone = 1;
									if (fifthone == 'x')
										xdone = 1;
									if (fifthone == 'y')
										ydone = 1;
									if (fifthone == 'z')
										zdone = 1;
								}
								else if (fifthone == keyone || fifthone == keytwo || fifthone == keythree || fifthone == keyfour || fifthone == keyfive)
								{
									fiveright = 2;
									if (fifthone == 'a')
										adone = 2;
									if (fifthone == 'b')
										bdone = 2;
									if (fifthone == 'c')
										cdone = 2;
									if (fifthone == 'd')
										ddone = 2;
									if (fifthone == 'e')
										edone = 2;
									if (fifthone == 'f')
										fdone = 2;
									if (fifthone == 'g')
										gdone = 2;
									if (fifthone == 'h')
										hdone = 2;
									if (fifthone == 'i')
										idone = 2;
									if (fifthone == 'j')
										jdone = 2;
									if (fifthone == 'k')
										kdone = 2;
									if (fifthone == 'l')
										ldone = 2;
									if (fifthone == 'm')
										mdone = 2;
									if (fifthone == 'n')
										ndone = 2;
									if (fifthone == 'o')
										odone = 2;
									if (fifthone == 'p')
										pdone = 2;
									if (fifthone == 'q')
										qdone = 2;
									if (fifthone == 'r')
										rdone = 2;
									if (fifthone == 's')
										sdone = 2;
									if (fifthone == 't')
										tdone = 2;
									if (fifthone == 'u')
										udone = 2;
									if (fifthone == 'v')
										vdone = 2;
									if (fifthone == 'w')
										wdone = 2;
									if (fifthone == 'x')
										xdone = 2;
									if (fifthone == 'y')
										ydone = 2;
									if (fifthone == 'z')
										zdone = 2;

								}
								else{
									fiveright = 0;
								if (fifthone == 'a')
									adone = 3;
								if (fifthone == 'b')
									bdone = 3;
								if (fifthone == 'c')
									cdone = 3;
								if (fifthone == 'd')
									ddone = 3;
								if (fifthone == 'e')
									edone = 3;
								if (fifthone == 'f')
									fdone = 3;
								if (fifthone == 'g')
									gdone = 3;
								if (fifthone == 'h')
									hdone = 3;
								if (fifthone == 'i')
									idone = 3;
								if (fifthone == 'j')
									jdone = 3;
								if (fifthone == 'k')
									kdone = 3;
								if (fifthone == 'l')
									ldone = 3;
								if (fifthone == 'm')
									mdone = 3;
								if (fifthone == 'n')
									ndone = 3;
								if (fifthone == 'o')
									odone = 3;
								if (fifthone == 'p')
									pdone = 3;
								if (fifthone == 'q')
									qdone = 3;
								if (fifthone == 'r')
									rdone = 3;
								if (fifthone == 's')
									sdone = 3;
								if (fifthone == 't')
									tdone = 3;
								if (fifthone == 'u')
									udone = 3;
								if (fifthone == 'v')
									vdone = 3;
								if (fifthone == 'w')
									wdone = 3;
								if (fifthone == 'x')
									xdone = 3;
								if (fifthone == 'y')
									ydone = 3;
								if (fifthone == 'z')
									zdone = 3;
							}
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							
								//std::cout << past_guess1[0] << past_guess1[1] << past_guess1[2] << past_guess1[3] << past_guess1[4] << past_guess1[5] << std::endl;
								past_guess_one_letter_one.setString(past_guess1[0]);
								past_guess_one_letter_two.setString(past_guess1[1]);
								past_guess_one_letter_three.setString(past_guess1[2]);
								past_guess_one_letter_four.setString(past_guess1[3]);
								past_guess_one_letter_five.setString(past_guess1[4]);
								if (firstone == answer_list.at(0) && secondone == answer_list.at(1) && thirdone == answer_list.at(2) && fourthone == answer_list.at(3) && fifthone == answer_list.at(4))
								{
									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;

								}
								guess->clear();
								++ticker;
								break;
							}
							if (ticker == 2)
							{
								past_guess2[0] = guess[0];
								past_guess2[1] = guess[1];
								past_guess2[2] = guess[2];
								past_guess2[3] = guess[3];
								past_guess2[4] = guess[4];
								guess->clear();
								char sixthone{ past_guess2->at(0) };
								char seventhone{ past_guess2->at(1) };
								char eighthone{ past_guess2->at(2) };
								char ninthone{ past_guess2->at(3) };
								char tenthone{ past_guess2->at(4) };
							
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
									////////////////////////////////////////////////////////////////////

								if (sixthone == answer_list.at(0))
								{
									sixright = 1;
									if (sixthone == 'a')
										adone = 1;
									if (sixthone == 'b')
										bdone = 1;
									if (sixthone == 'c')
										cdone = 1;
									if (sixthone == 'd')
										ddone = 1;
									if (sixthone == 'e')
										edone = 1;
									if (sixthone == 'f')
										fdone = 1;
									if (sixthone == 'g')
										gdone = 1;
									if (sixthone == 'h')
										hdone = 1;
									if (sixthone == 'i')
										idone = 1;
									if (sixthone == 'j')
										jdone = 1;
									if (sixthone == 'k')
										kdone = 1;
									if (sixthone == 'l')
										ldone = 1;
									if (sixthone == 'm')
										mdone = 1;
									if (sixthone == 'n')
										ndone = 1;
									if (sixthone == 'o')
										odone = 1;
									if (sixthone == 'p')
										pdone = 1;
									if (sixthone == 'q')
										qdone = 1;
									if (sixthone == 'r')
										rdone = 1;
									if (sixthone == 's')
										sdone = 1;
									if (sixthone == 't')
										tdone = 1;
									if (sixthone == 'u')
										udone = 1;
									if (sixthone == 'v')
										vdone = 1;
									if (sixthone == 'w')
										wdone = 1;
									if (sixthone == 'x')
										xdone = 1;
									if (sixthone == 'y')
										ydone = 1;
									if (sixthone == 'z')
										zdone = 1;
								}
								else if (sixthone == keyone || sixthone == keytwo || sixthone == keythree || sixthone == keyfour || sixthone == keyfive)
								{
									sixright = 2;
									if (sixthone == 'a')
										adone = 2;
									if (sixthone == 'b')
										bdone = 2;
									if (sixthone == 'c')
										cdone = 2;
									if (sixthone == 'd')
										ddone = 2;
									if (sixthone == 'e')
										edone = 2;
									if (sixthone == 'f')
										fdone = 2;
									if (sixthone == 'g')
										gdone = 2;
									if (sixthone == 'h')
										hdone = 2;
									if (sixthone == 'i')
										idone = 2;
									if (sixthone == 'j')
										jdone = 2;
									if (sixthone == 'k')
										kdone = 2;
									if (sixthone == 'l')
										ldone = 2;
									if (sixthone == 'm')
										mdone = 2;
									if (sixthone == 'n')
										ndone = 2;
									if (sixthone == 'o')
										odone = 2;
									if (sixthone == 'p')
										pdone = 2;
									if (sixthone == 'q')
										qdone = 2;
									if (sixthone == 'r')
										rdone = 2;
									if (sixthone == 's')
										sdone = 2;
									if (sixthone == 't')
										tdone = 2;
									if (sixthone == 'u')
										udone = 2;
									if (sixthone == 'v')
										vdone = 2;
									if (sixthone == 'w')
										wdone = 2;
									if (sixthone == 'x')
										xdone = 2;
									if (sixthone == 'y')
										ydone = 2;
									if (sixthone == 'z')
										zdone = 2;

								}
								else{
									sixright = 0;
								if (sixthone == 'a')
									adone = 3;
								if (sixthone == 'b')
									bdone = 3;
								if (sixthone == 'c')
									cdone = 3;
								if (sixthone == 'd')
									ddone = 3;
								if (sixthone == 'e')
									edone = 3;
								if (sixthone == 'f')
									fdone = 3;
								if (sixthone == 'g')
									gdone = 3;
								if (sixthone == 'h')
									hdone = 3;
								if (sixthone == 'i')
									idone = 3;
								if (sixthone == 'j')
									jdone = 3;
								if (sixthone == 'k')
									kdone = 3;
								if (sixthone == 'l')
									ldone = 3;
								if (sixthone == 'm')
									mdone = 3;
								if (sixthone == 'n')
									ndone = 3;
								if (sixthone == 'o')
									odone = 3;
								if (sixthone == 'p')
									pdone = 3;
								if (sixthone == 'q')
									qdone = 3;
								if (sixthone == 'r')
									rdone = 3;
								if (sixthone == 's')
									sdone = 3;
								if (sixthone == 't')
									tdone = 3;
								if (sixthone == 'u')
									udone = 3;
								if (sixthone == 'v')
									vdone = 3;
								if (sixthone == 'w')
									wdone = 3;
								if (sixthone == 'x')
									xdone = 3;
								if (sixthone == 'y')
									ydone = 3;
								if (sixthone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (seventhone == answer_list.at(1))
								{
									sevenright = 1;
									if (seventhone == 'a')
										adone = 1;
									if (seventhone == 'b')
										bdone = 1;
									if (seventhone == 'c')
										cdone = 1;
									if (seventhone == 'd')
										ddone = 1;
									if (seventhone == 'e')
										edone = 1;
									if (seventhone == 'f')
										fdone = 1;
									if (seventhone == 'g')
										gdone = 1;
									if (seventhone == 'h')
										hdone = 1;
									if (seventhone == 'i')
										idone = 1;
									if (seventhone == 'j')
										jdone = 1;
									if (seventhone == 'k')
										kdone = 1;
									if (seventhone == 'l')
										ldone = 1;
									if (seventhone == 'm')
										mdone = 1;
									if (seventhone == 'n')
										ndone = 1;
									if (seventhone == 'o')
										odone = 1;
									if (seventhone == 'p')
										pdone = 1;
									if (seventhone == 'q')
										qdone = 1;
									if (seventhone == 'r')
										rdone = 1;
									if (seventhone == 's')
										sdone = 1;
									if (seventhone == 't')
										tdone = 1;
									if (seventhone == 'u')
										udone = 1;
									if (seventhone == 'v')
										vdone = 1;
									if (seventhone == 'w')
										wdone = 1;
									if (seventhone == 'x')
										xdone = 1;
									if (seventhone == 'y')
										ydone = 1;
									if (seventhone == 'z')
										zdone = 1;
								}
								else if (seventhone == keyone || seventhone == keytwo || seventhone == keythree || seventhone == keyfour || seventhone == keyfive)
								{
									sevenright = 2;
									if (seventhone == 'a')
										adone = 2;
									if (seventhone == 'b')
										bdone = 2;
									if (seventhone == 'c')
										cdone = 2;
									if (seventhone == 'd')
										ddone = 2;
									if (seventhone == 'e')
										edone = 2;
									if (seventhone == 'f')
										fdone = 2;
									if (seventhone == 'g')
										gdone = 2;
									if (seventhone == 'h')
										hdone = 2;
									if (seventhone == 'i')
										idone = 2;
									if (seventhone == 'j')
										jdone = 2;
									if (seventhone == 'k')
										kdone = 2;
									if (seventhone == 'l')
										ldone = 2;
									if (seventhone == 'm')
										mdone = 2;
									if (seventhone == 'n')
										ndone = 2;
									if (seventhone == 'o')
										odone = 2;
									if (seventhone == 'p')
										pdone = 2;
									if (seventhone == 'q')
										qdone = 2;
									if (seventhone == 'r')
										rdone = 2;
									if (seventhone == 's')
										sdone = 2;
									if (seventhone == 't')
										tdone = 2;
									if (seventhone == 'u')
										udone = 2;
									if (seventhone == 'v')
										vdone = 2;
									if (seventhone == 'w')
										wdone = 2;
									if (seventhone == 'x')
										xdone = 2;
									if (seventhone == 'y')
										ydone = 2;
									if (seventhone == 'z')
										zdone = 2;

								}
								else{
									sevenright = 0;
								if (seventhone == 'a')
									adone = 3;
								if (seventhone == 'b')
									bdone = 3;
								if (seventhone == 'c')
									cdone = 3;
								if (seventhone == 'd')
									ddone = 3;
								if (seventhone == 'e')
									edone = 3;
								if (seventhone == 'f')
									fdone = 3;
								if (seventhone == 'g')
									gdone = 3;
								if (seventhone == 'h')
									hdone = 3;
								if (seventhone == 'i')
									idone = 3;
								if (seventhone == 'j')
									jdone = 3;
								if (seventhone == 'k')
									kdone = 3;
								if (seventhone == 'l')
									ldone = 3;
								if (seventhone == 'm')
									mdone = 3;
								if (seventhone == 'n')
									ndone = 3;
								if (seventhone == 'o')
									odone = 3;
								if (seventhone == 'p')
									pdone = 3;
								if (seventhone == 'q')
									qdone = 3;
								if (seventhone == 'r')
									rdone = 3;
								if (seventhone == 's')
									sdone = 3;
								if (seventhone == 't')
									tdone = 3;
								if (seventhone == 'u')
									udone = 3;
								if (seventhone == 'v')
									vdone = 3;
								if (seventhone == 'w')
									wdone = 3;
								if (seventhone == 'x')
									xdone = 3;
								if (seventhone == 'y')
									ydone = 3;
								if (seventhone == 'z')
									zdone = 3;
							}

								////////////////////////////////////////////////////////////////////

								if (eighthone == answer_list.at(2))
								{
									eightright = 1;
									if (eighthone == 'a')
										adone = 1;
									if (eighthone == 'b')
										bdone = 1;
									if (eighthone == 'c')
										cdone = 1;
									if (eighthone == 'd')
										ddone = 1;
									if (eighthone == 'e')
										edone = 1;
									if (eighthone == 'f')
										fdone = 1;
									if (eighthone == 'g')
										gdone = 1;
									if (eighthone == 'h')
										hdone = 1;
									if (eighthone == 'i')
										idone = 1;
									if (eighthone == 'j')
										jdone = 1;
									if (eighthone == 'k')
										kdone = 1;
									if (eighthone == 'l')
										ldone = 1;
									if (eighthone == 'm')
										mdone = 1;
									if (eighthone == 'n')
										ndone = 1;
									if (eighthone == 'o')
										odone = 1;
									if (eighthone == 'p')
										pdone = 1;
									if (eighthone == 'q')
										qdone = 1;
									if (eighthone == 'r')
										rdone = 1;
									if (eighthone == 's')
										sdone = 1;
									if (eighthone == 't')
										tdone = 1;
									if (eighthone == 'u')
										udone = 1;
									if (eighthone == 'v')
										vdone = 1;
									if (eighthone == 'w')
										wdone = 1;
									if (eighthone == 'x')
										xdone = 1;
									if (eighthone == 'y')
										ydone = 1;
									if (eighthone == 'z')
										zdone = 1;
								}
								else if (eighthone == keyone || eighthone == keytwo || eighthone == keythree || eighthone == keyfour || eighthone == keyfive)
								{
									eightright = 2;
									if (eighthone == 'a')
										adone = 2;
									if (eighthone == 'b')
										bdone = 2;
									if (eighthone == 'c')
										cdone = 2;
									if (eighthone == 'd')
										ddone = 2;
									if (eighthone == 'e')
										edone = 2;
									if (eighthone == 'f')
										fdone = 2;
									if (eighthone == 'g')
										gdone = 2;
									if (eighthone == 'h')
										hdone = 2;
									if (eighthone == 'i')
										idone = 2;
									if (eighthone == 'j')
										jdone = 2;
									if (eighthone == 'k')
										kdone = 2;
									if (eighthone == 'l')
										ldone = 2;
									if (eighthone == 'm')
										mdone = 2;
									if (eighthone == 'n')
										ndone = 2;
									if (eighthone == 'o')
										odone = 2;
									if (eighthone == 'p')
										pdone = 2;
									if (eighthone == 'q')
										qdone = 2;
									if (eighthone == 'r')
										rdone = 2;
									if (eighthone == 's')
										sdone = 2;
									if (eighthone == 't')
										tdone = 2;
									if (eighthone == 'u')
										udone = 2;
									if (eighthone == 'v')
										vdone = 2;
									if (eighthone == 'w')
										wdone = 2;
									if (eighthone == 'x')
										xdone = 2;
									if (eighthone == 'y')
										ydone = 2;
									if (eighthone == 'z')
										zdone = 2;

								}
								else{
									eightright = 0;
								if (eighthone == 'a')
									adone = 3;
								if (eighthone == 'b')
									bdone = 3;
								if (eighthone == 'c')
									cdone = 3;
								if (eighthone == 'd')
									ddone = 3;
								if (eighthone == 'e')
									edone = 3;
								if (eighthone == 'f')
									fdone = 3;
								if (eighthone == 'g')
									gdone = 3;
								if (eighthone == 'h')
									hdone = 3;
								if (eighthone == 'i')
									idone = 3;
								if (eighthone == 'j')
									jdone = 3;
								if (eighthone == 'k')
									kdone = 3;
								if (eighthone == 'l')
									ldone = 3;
								if (eighthone == 'm')
									mdone = 3;
								if (eighthone == 'n')
									ndone = 3;
								if (eighthone == 'o')
									odone = 3;
								if (eighthone == 'p')
									pdone = 3;
								if (eighthone == 'q')
									qdone = 3;
								if (eighthone == 'r')
									rdone = 3;
								if (eighthone == 's')
									sdone = 3;
								if (eighthone == 't')
									tdone = 3;
								if (eighthone == 'u')
									udone = 3;
								if (eighthone == 'v')
									vdone = 3;
								if (eighthone == 'w')
									wdone = 3;
								if (eighthone == 'x')
									xdone = 3;
								if (eighthone == 'y')
									ydone = 3;
								if (eighthone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (ninthone == answer_list.at(3))
								{
									nineright = 1;
									if (ninthone == 'a')
										adone = 1;
									if (ninthone == 'b')
										bdone = 1;
									if (ninthone == 'c')
										cdone = 1;
									if (ninthone == 'd')
										ddone = 1;
									if (ninthone == 'e')
										edone = 1;
									if (ninthone == 'f')
										fdone = 1;
									if (ninthone == 'g')
										gdone = 1;
									if (ninthone == 'h')
										hdone = 1;
									if (ninthone == 'i')
										idone = 1;
									if (ninthone == 'j')
										jdone = 1;
									if (ninthone == 'k')
										kdone = 1;
									if (ninthone == 'l')
										ldone = 1;
									if (ninthone == 'm')
										mdone = 1;
									if (ninthone == 'n')
										ndone = 1;
									if (ninthone == 'o')
										odone = 1;
									if (ninthone == 'p')
										pdone = 1;
									if (ninthone == 'q')
										qdone = 1;
									if (ninthone == 'r')
										rdone = 1;
									if (ninthone == 's')
										sdone = 1;
									if (ninthone == 't')
										tdone = 1;
									if (ninthone == 'u')
										udone = 1;
									if (ninthone == 'v')
										vdone = 1;
									if (ninthone == 'w')
										wdone = 1;
									if (ninthone == 'x')
										xdone = 1;
									if (ninthone == 'y')
										ydone = 1;
									if (ninthone == 'z')
										zdone = 1;
								}
								else if (ninthone == keyone || ninthone == keytwo || ninthone == keythree || ninthone == keyfour || ninthone == keyfive)
								{
									nineright = 2;
									if (ninthone == 'a')
										adone = 2;
									if (ninthone == 'b')
										bdone = 2;
									if (ninthone == 'c')
										cdone = 2;
									if (ninthone == 'd')
										ddone = 2;
									if (ninthone == 'e')
										edone = 2;
									if (ninthone == 'f')
										fdone = 2;
									if (ninthone == 'g')
										gdone = 2;
									if (ninthone == 'h')
										hdone = 2;
									if (ninthone == 'i')
										idone = 2;
									if (ninthone == 'j')
										jdone = 2;
									if (ninthone == 'k')
										kdone = 2;
									if (ninthone == 'l')
										ldone = 2;
									if (ninthone == 'm')
										mdone = 2;
									if (ninthone == 'n')
										ndone = 2;
									if (ninthone == 'o')
										odone = 2;
									if (ninthone == 'p')
										pdone = 2;
									if (ninthone == 'q')
										qdone = 2;
									if (ninthone == 'r')
										rdone = 2;
									if (ninthone == 's')
										sdone = 2;
									if (ninthone == 't')
										tdone = 2;
									if (ninthone == 'u')
										udone = 2;
									if (ninthone == 'v')
										vdone = 2;
									if (ninthone == 'w')
										wdone = 2;
									if (ninthone == 'x')
										xdone = 2;
									if (ninthone == 'y')
										ydone = 2;
									if (ninthone == 'z')
										zdone = 2;

								}
								else{
									nineright = 0;
								if (ninthone == 'a')
									adone = 3;
								if (ninthone == 'b')
									bdone = 3;
								if (ninthone == 'c')
									cdone = 3;
								if (ninthone == 'd')
									ddone = 3;
								if (ninthone == 'e')
									edone = 3;
								if (ninthone == 'f')
									fdone = 3;
								if (ninthone == 'g')
									gdone = 3;
								if (ninthone == 'h')
									hdone = 3;
								if (ninthone == 'i')
									idone = 3;
								if (ninthone == 'j')
									jdone = 3;
								if (ninthone == 'k')
									kdone = 3;
								if (ninthone == 'l')
									ldone = 3;
								if (ninthone == 'm')
									mdone = 3;
								if (ninthone == 'n')
									ndone = 3;
								if (ninthone == 'o')
									odone = 3;
								if (ninthone == 'p')
									pdone = 3;
								if (ninthone == 'q')
									qdone = 3;
								if (ninthone == 'r')
									rdone = 3;
								if (ninthone == 's')
									sdone = 3;
								if (ninthone == 't')
									tdone = 3;
								if (ninthone == 'u')
									udone = 3;
								if (ninthone == 'v')
									vdone = 3;
								if (ninthone == 'w')
									wdone = 3;
								if (ninthone == 'x')
									xdone = 3;
								if (ninthone == 'y')
									ydone = 3;
								if (ninthone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (tenthone == answer_list.at(4))
								{
									tenright = 1;
									if (tenthone == 'a')
										adone = 1;
									if (tenthone == 'b')
										bdone = 1;
									if (tenthone == 'c')
										cdone = 1;
									if (tenthone == 'd')
										ddone = 1;
									if (tenthone == 'e')
										edone = 1;
									if (tenthone == 'f')
										fdone = 1;
									if (tenthone == 'g')
										gdone = 1;
									if (tenthone == 'h')
										hdone = 1;
									if (tenthone == 'i')
										idone = 1;
									if (tenthone == 'j')
										jdone = 1;
									if (tenthone == 'k')
										kdone = 1;
									if (tenthone == 'l')
										ldone = 1;
									if (tenthone == 'm')
										mdone = 1;
									if (tenthone == 'n')
										ndone = 1;
									if (tenthone == 'o')
										odone = 1;
									if (tenthone == 'p')
										pdone = 1;
									if (tenthone == 'q')
										qdone = 1;
									if (tenthone == 'r')
										rdone = 1;
									if (tenthone == 's')
										sdone = 1;
									if (tenthone == 't')
										tdone = 1;
									if (tenthone == 'u')
										udone = 1;
									if (tenthone == 'v')
										vdone = 1;
									if (tenthone == 'w')
										wdone = 1;
									if (tenthone == 'x')
										xdone = 1;
									if (tenthone == 'y')
										ydone = 1;
									if (tenthone == 'z')
										zdone = 1;
								}
								else if (tenthone == keyone || tenthone == keytwo || tenthone == keythree || tenthone == keyfour || tenthone == keyfive)
								{
									tenright = 2;
									if (tenthone == 'a')
										adone = 2;
									if (tenthone == 'b')
										bdone = 2;
									if (tenthone == 'c')
										cdone = 2;
									if (tenthone == 'd')
										ddone = 2;
									if (tenthone == 'e')
										edone = 2;
									if (tenthone == 'f')
										fdone = 2;
									if (tenthone == 'g')
										gdone = 2;
									if (tenthone == 'h')
										hdone = 2;
									if (tenthone == 'i')
										idone = 2;
									if (tenthone == 'j')
										jdone = 2;
									if (tenthone == 'k')
										kdone = 2;
									if (tenthone == 'l')
										ldone = 2;
									if (tenthone == 'm')
										mdone = 2;
									if (tenthone == 'n')
										ndone = 2;
									if (tenthone == 'o')
										odone = 2;
									if (tenthone == 'p')
										pdone = 2;
									if (tenthone == 'q')
										qdone = 2;
									if (tenthone == 'r')
										rdone = 2;
									if (tenthone == 's')
										sdone = 2;
									if (tenthone == 't')
										tdone = 2;
									if (tenthone == 'u')
										udone = 2;
									if (tenthone == 'v')
										vdone = 2;
									if (tenthone == 'w')
										wdone = 2;
									if (tenthone == 'x')
										xdone = 2;
									if (tenthone == 'y')
										ydone = 2;
									if (tenthone == 'z')
										zdone = 2;

								}
								else{
									tenright = 0;
								if (tenthone == 'a')
									adone = 3;
								if (tenthone == 'b')
									bdone = 3;
								if (tenthone == 'c')
									cdone = 3;
								if (tenthone == 'd')
									ddone = 3;
								if (tenthone == 'e')
									edone = 3;
								if (tenthone == 'f')
									fdone = 3;
								if (tenthone == 'g')
									gdone = 3;
								if (tenthone == 'h')
									hdone = 3;
								if (tenthone == 'i')
									idone = 3;
								if (tenthone == 'j')
									jdone = 3;
								if (tenthone == 'k')
									kdone = 3;
								if (tenthone == 'l')
									ldone = 3;
								if (tenthone == 'm')
									mdone = 3;
								if (tenthone == 'n')
									ndone = 3;
								if (tenthone == 'o')
									odone = 3;
								if (tenthone == 'p')
									pdone = 3;
								if (tenthone == 'q')
									qdone = 3;
								if (tenthone == 'r')
									rdone = 3;
								if (tenthone == 's')
									sdone = 3;
								if (tenthone == 't')
									tdone = 3;
								if (tenthone == 'u')
									udone = 3;
								if (tenthone == 'v')
									vdone = 3;
								if (tenthone == 'w')
									wdone = 3;
								if (tenthone == 'x')
									xdone = 3;
								if (tenthone == 'y')
									ydone = 3;
								if (tenthone == 'z')
									zdone = 3;
							}
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								
								std::cout << answer << std::endl;
							
							
								past_guess_two_letter_one.setString(past_guess2[0]);
								past_guess_two_letter_two.setString(past_guess2[1]);
								past_guess_two_letter_three.setString(past_guess2[2]);
								past_guess_two_letter_four.setString(past_guess2[3]);
								past_guess_two_letter_five.setString(past_guess2[4]);
								if (sixthone == answer_list.at(0) && seventhone == answer_list.at(1) && eighthone == answer_list.at(2) && ninthone == answer_list.at(3) && tenthone == answer_list.at(4))
								{
									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;

								}
								guess->clear();
								++ticker;
								break;
							}
							
							if (ticker == 3)
							{
								past_guess3[0] = guess[0];
								past_guess3[1] = guess[1];
								past_guess3[2] = guess[2];
								past_guess3[3] = guess[3];
								past_guess3[4] = guess[4];
								guess->clear();
								std::cout << answer << std::endl << std::endl;
								char eleventhone{ past_guess3->at(0) };
								char twelthone{ past_guess3->at(1) };
								char thirteenthone{ past_guess3->at(2) };
								char fourteenthone{ past_guess3->at(3) };
								char fifteenthone{ past_guess3->at(4) };
							
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																////////////////////////////////////////////////////////////////////

								if (eleventhone == answer_list.at(0))
								{
									elevenright = 1;
									if (eleventhone == 'a')
										adone = 1;
									if (eleventhone == 'b')
										bdone = 1;
									if (eleventhone == 'c')
										cdone = 1;
									if (eleventhone == 'd')
										ddone = 1;
									if (eleventhone == 'e')
										edone = 1;
									if (eleventhone == 'f')
										fdone = 1;
									if (eleventhone == 'g')
										gdone = 1;
									if (eleventhone == 'h')
										hdone = 1;
									if (eleventhone == 'i')
										idone = 1;
									if (eleventhone == 'j')
										jdone = 1;
									if (eleventhone == 'k')
										kdone = 1;
									if (eleventhone == 'l')
										ldone = 1;
									if (eleventhone == 'm')
										mdone = 1;
									if (eleventhone == 'n')
										ndone = 1;
									if (eleventhone == 'o')
										odone = 1;
									if (eleventhone == 'p')
										pdone = 1;
									if (eleventhone == 'q')
										qdone = 1;
									if (eleventhone == 'r')
										rdone = 1;
									if (eleventhone == 's')
										sdone = 1;
									if (eleventhone == 't')
										tdone = 1;
									if (eleventhone == 'u')
										udone = 1;
									if (eleventhone == 'v')
										vdone = 1;
									if (eleventhone == 'w')
										wdone = 1;
									if (eleventhone == 'x')
										xdone = 1;
									if (eleventhone == 'y')
										ydone = 1;
									if (eleventhone == 'z')
										zdone = 1;
								}
								else if (eleventhone == keyone || eleventhone == keytwo || eleventhone == keythree || eleventhone == keyfour || eleventhone == keyfive)
								{
									elevenright = 2;
									if (eleventhone == 'a')
										adone = 2;
									if (eleventhone == 'b')
										bdone = 2;
									if (eleventhone == 'c')
										cdone = 2;
									if (eleventhone == 'd')
										ddone = 2;
									if (eleventhone == 'e')
										edone = 2;
									if (eleventhone == 'f')
										fdone = 2;
									if (eleventhone == 'g')
										gdone = 2;
									if (eleventhone == 'h')
										hdone = 2;
									if (eleventhone == 'i')
										idone = 2;
									if (eleventhone == 'j')
										jdone = 2;
									if (eleventhone == 'k')
										kdone = 2;
									if (eleventhone == 'l')
										ldone = 2;
									if (eleventhone == 'm')
										mdone = 2;
									if (eleventhone == 'n')
										ndone = 2;
									if (eleventhone == 'o')
										odone = 2;
									if (eleventhone == 'p')
										pdone = 2;
									if (eleventhone == 'q')
										qdone = 2;
									if (eleventhone == 'r')
										rdone = 2;
									if (eleventhone == 's')
										sdone = 2;
									if (eleventhone == 't')
										tdone = 2;
									if (eleventhone == 'u')
										udone = 2;
									if (eleventhone == 'v')
										vdone = 2;
									if (eleventhone == 'w')
										wdone = 2;
									if (eleventhone == 'x')
										xdone = 2;
									if (eleventhone == 'y')
										ydone = 2;
									if (eleventhone == 'z')
										zdone = 2;

								}
								else{
									elevenright = 0;
								if (eleventhone == 'a')
									adone = 3;
								if (eleventhone == 'b')
									bdone = 3;
								if (eleventhone == 'c')
									cdone = 3;
								if (eleventhone == 'd')
									ddone = 3;
								if (eleventhone == 'e')
									edone = 3;
								if (eleventhone == 'f')
									fdone = 3;
								if (eleventhone == 'g')
									gdone = 3;
								if (eleventhone == 'h')
									hdone = 3;
								if (eleventhone == 'i')
									idone = 3;
								if (eleventhone == 'j')
									jdone = 3;
								if (eleventhone == 'k')
									kdone = 3;
								if (eleventhone == 'l')
									ldone = 3;
								if (eleventhone == 'm')
									mdone = 3;
								if (eleventhone == 'n')
									ndone = 3;
								if (eleventhone == 'o')
									odone = 3;
								if (eleventhone == 'p')
									pdone = 3;
								if (eleventhone == 'q')
									qdone = 3;
								if (eleventhone == 'r')
									rdone = 3;
								if (eleventhone == 's')
									sdone = 3;
								if (eleventhone == 't')
									tdone = 3;
								if (eleventhone == 'u')
									udone = 3;
								if (eleventhone == 'v')
									vdone = 3;
								if (eleventhone == 'w')
									wdone = 3;
								if (eleventhone == 'x')
									xdone = 3;
								if (eleventhone == 'y')
									ydone = 3;
								if (eleventhone == 'z')
									zdone = 3;
							}

								////////////////////////////////////////////////////////////////////

								if (twelthone == answer_list.at(1))
								{
									twelveright = 1;
									if (twelthone == 'a')
										adone = 1;
									if (twelthone == 'b')
										bdone = 1;
									if (twelthone == 'c')
										cdone = 1;
									if (twelthone == 'd')
										ddone = 1;
									if (twelthone == 'e')
										edone = 1;
									if (twelthone == 'f')
										fdone = 1;
									if (twelthone == 'g')
										gdone = 1;
									if (twelthone == 'h')
										hdone = 1;
									if (twelthone == 'i')
										idone = 1;
									if (twelthone == 'j')
										jdone = 1;
									if (twelthone == 'k')
										kdone = 1;
									if (twelthone == 'l')
										ldone = 1;
									if (twelthone == 'm')
										mdone = 1;
									if (twelthone == 'n')
										ndone = 1;
									if (twelthone == 'o')
										odone = 1;
									if (twelthone == 'p')
										pdone = 1;
									if (twelthone == 'q')
										qdone = 1;
									if (twelthone == 'r')
										rdone = 1;
									if (twelthone == 's')
										sdone = 1;
									if (twelthone == 't')
										tdone = 1;
									if (twelthone == 'u')
										udone = 1;
									if (twelthone == 'v')
										vdone = 1;
									if (twelthone == 'w')
										wdone = 1;
									if (twelthone == 'x')
										xdone = 1;
									if (twelthone == 'y')
										ydone = 1;
									if (twelthone == 'z')
										zdone = 1;
								}
								else if (twelthone == keyone || twelthone == keytwo || twelthone == keythree || twelthone == keyfour || twelthone == keyfive)
								{
									twelveright = 2;
									if (twelthone == 'a')
										adone = 2;
									if (twelthone == 'b')
										bdone = 2;
									if (twelthone == 'c')
										cdone = 2;
									if (twelthone == 'd')
										ddone = 2;
									if (twelthone == 'e')
										edone = 2;
									if (twelthone == 'f')
										fdone = 2;
									if (twelthone == 'g')
										gdone = 2;
									if (twelthone == 'h')
										hdone = 2;
									if (twelthone == 'i')
										idone = 2;
									if (twelthone == 'j')
										jdone = 2;
									if (twelthone == 'k')
										kdone = 2;
									if (twelthone == 'l')
										ldone = 2;
									if (twelthone == 'm')
										mdone = 2;
									if (twelthone == 'n')
										ndone = 2;
									if (twelthone == 'o')
										odone = 2;
									if (twelthone == 'p')
										pdone = 2;
									if (twelthone == 'q')
										qdone = 2;
									if (twelthone == 'r')
										rdone = 2;
									if (twelthone == 's')
										sdone = 2;
									if (twelthone == 't')
										tdone = 2;
									if (twelthone == 'u')
										udone = 2;
									if (twelthone == 'v')
										vdone = 2;
									if (twelthone == 'w')
										wdone = 2;
									if (twelthone == 'x')
										xdone = 2;
									if (twelthone == 'y')
										ydone = 2;
									if (twelthone == 'z')
										zdone = 2;

								}
								else{
									twelveright = 0;
								if (twelthone == 'a')
									adone = 3;
								if (twelthone == 'b')
									bdone = 3;
								if (twelthone == 'c')
									cdone = 3;
								if (twelthone == 'd')
									ddone = 3;
								if (twelthone == 'e')
									edone = 3;
								if (twelthone == 'f')
									fdone = 3;
								if (twelthone == 'g')
									gdone = 3;
								if (twelthone == 'h')
									hdone = 3;
								if (twelthone == 'i')
									idone = 3;
								if (twelthone == 'j')
									jdone = 3;
								if (twelthone == 'k')
									kdone = 3;
								if (twelthone == 'l')
									ldone = 3;
								if (twelthone == 'm')
									mdone = 3;
								if (twelthone == 'n')
									ndone = 3;
								if (twelthone == 'o')
									odone = 3;
								if (twelthone == 'p')
									pdone = 3;
								if (twelthone == 'q')
									qdone = 3;
								if (twelthone == 'r')
									rdone = 3;
								if (twelthone == 's')
									sdone = 3;
								if (twelthone == 't')
									tdone = 3;
								if (twelthone == 'u')
									udone = 3;
								if (twelthone == 'v')
									vdone = 3;
								if (twelthone == 'w')
									wdone = 3;
								if (twelthone == 'x')
									xdone = 3;
								if (twelthone == 'y')
									ydone = 3;
								if (twelthone == 'z')
									zdone = 3;
							}
								////////////////////////////////////////////////////////////////////

								if (thirteenthone == answer_list.at(2))
								{
									thirteenright = 1;
									if (thirteenthone == 'a')
										adone = 1;
									if (thirteenthone == 'b')
										bdone = 1;
									if (thirteenthone == 'c')
										cdone = 1;
									if (thirteenthone == 'd')
										ddone = 1;
									if (thirteenthone == 'e')
										edone = 1;
									if (thirteenthone == 'f')
										fdone = 1;
									if (thirteenthone == 'g')
										gdone = 1;
									if (thirteenthone == 'h')
										hdone = 1;
									if (thirteenthone == 'i')
										idone = 1;
									if (thirteenthone == 'j')
										jdone = 1;
									if (thirteenthone == 'k')
										kdone = 1;
									if (thirteenthone == 'l')
										ldone = 1;
									if (thirteenthone == 'm')
										mdone = 1;
									if (thirteenthone == 'n')
										ndone = 1;
									if (thirteenthone == 'o')
										odone = 1;
									if (thirteenthone == 'p')
										pdone = 1;
									if (thirteenthone == 'q')
										qdone = 1;
									if (thirteenthone == 'r')
										rdone = 1;
									if (thirteenthone == 's')
										sdone = 1;
									if (thirteenthone == 't')
										tdone = 1;
									if (thirteenthone == 'u')
										udone = 1;
									if (thirteenthone == 'v')
										vdone = 1;
									if (thirteenthone == 'w')
										wdone = 1;
									if (thirteenthone == 'x')
										xdone = 1;
									if (thirteenthone == 'y')
										ydone = 1;
									if (thirteenthone == 'z')
										zdone = 1;
								}
								else if (thirteenthone == keyone || thirteenthone == keytwo || thirteenthone == keythree || thirteenthone == keyfour || thirteenthone == keyfive)
								{
									thirteenright = 2;
									if (thirteenthone == 'a')
										adone = 2;
									if (thirteenthone == 'b')
										bdone = 2;
									if (thirteenthone == 'c')
										cdone = 2;
									if (thirteenthone == 'd')
										ddone = 2;
									if (thirteenthone == 'e')
										edone = 2;
									if (thirteenthone == 'f')
										fdone = 2;
									if (thirteenthone == 'g')
										gdone = 2;
									if (thirteenthone == 'h')
										hdone = 2;
									if (thirteenthone == 'i')
										idone = 2;
									if (thirteenthone == 'j')
										jdone = 2;
									if (thirteenthone == 'k')
										kdone = 2;
									if (thirteenthone == 'l')
										ldone = 2;
									if (thirteenthone == 'm')
										mdone = 2;
									if (thirteenthone == 'n')
										ndone = 2;
									if (thirteenthone == 'o')
										odone = 2;
									if (thirteenthone == 'p')
										pdone = 2;
									if (thirteenthone == 'q')
										qdone = 2;
									if (thirteenthone == 'r')
										rdone = 2;
									if (thirteenthone == 's')
										sdone = 2;
									if (thirteenthone == 't')
										tdone = 2;
									if (thirteenthone == 'u')
										udone = 2;
									if (thirteenthone == 'v')
										vdone = 2;
									if (thirteenthone == 'w')
										wdone = 2;
									if (thirteenthone == 'x')
										xdone = 2;
									if (thirteenthone == 'y')
										ydone = 2;
									if (thirteenthone == 'z')
										zdone = 2;

								}
								else{
									thirteenright = 0;
								if (thirteenthone == 'a')
									adone = 3;
								if (thirteenthone == 'b')
									bdone = 3;
								if (thirteenthone == 'c')
									cdone = 3;
								if (thirteenthone == 'd')
									ddone = 3;
								if (thirteenthone == 'e')
									edone = 3;
								if (thirteenthone == 'f')
									fdone = 3;
								if (thirteenthone == 'g')
									gdone = 3;
								if (thirteenthone == 'h')
									hdone = 3;
								if (thirteenthone == 'i')
									idone = 3;
								if (thirteenthone == 'j')
									jdone = 3;
								if (thirteenthone == 'k')
									kdone = 3;
								if (thirteenthone == 'l')
									ldone = 3;
								if (thirteenthone == 'm')
									mdone = 3;
								if (thirteenthone == 'n')
									ndone = 3;
								if (thirteenthone == 'o')
									odone = 3;
								if (thirteenthone == 'p')
									pdone = 3;
								if (thirteenthone == 'q')
									qdone = 3;
								if (thirteenthone == 'r')
									rdone = 3;
								if (thirteenthone == 's')
									sdone = 3;
								if (thirteenthone == 't')
									tdone = 3;
								if (thirteenthone == 'u')
									udone = 3;
								if (thirteenthone == 'v')
									vdone = 3;
								if (thirteenthone == 'w')
									wdone = 3;
								if (thirteenthone == 'x')
									xdone = 3;
								if (thirteenthone == 'y')
									ydone = 3;
								if (thirteenthone == 'z')
									zdone = 3;
							}
																////////////////////////////////////////////////////////////////////

								if (fourteenthone == answer_list.at(3))
								{
									fourteenright = 1;
									if (fourteenthone == 'a')
										adone = 1;
									if (fourteenthone == 'b')
										bdone = 1;
									if (fourteenthone == 'c')
										cdone = 1;
									if (fourteenthone == 'd')
										ddone = 1;
									if (fourteenthone == 'e')
										edone = 1;
									if (fourteenthone == 'f')
										fdone = 1;
									if (fourteenthone == 'g')
										gdone = 1;
									if (fourteenthone == 'h')
										hdone = 1;
									if (fourteenthone == 'i')
										idone = 1;
									if (fourteenthone == 'j')
										jdone = 1;
									if (fourteenthone == 'k')
										kdone = 1;
									if (fourteenthone == 'l')
										ldone = 1;
									if (fourteenthone == 'm')
										mdone = 1;
									if (fourteenthone == 'n')
										ndone = 1;
									if (fourteenthone == 'o')
										odone = 1;
									if (fourteenthone == 'p')
										pdone = 1;
									if (fourteenthone == 'q')
										qdone = 1;
									if (fourteenthone == 'r')
										rdone = 1;
									if (fourteenthone == 's')
										sdone = 1;
									if (fourteenthone == 't')
										tdone = 1;
									if (fourteenthone == 'u')
										udone = 1;
									if (fourteenthone == 'v')
										vdone = 1;
									if (fourteenthone == 'w')
										wdone = 1;
									if (fourteenthone == 'x')
										xdone = 1;
									if (fourteenthone == 'y')
										ydone = 1;
									if (fourteenthone == 'z')
										zdone = 1;
								}
								else if (fourteenthone == keyone || fourteenthone == keytwo || fourteenthone == keythree || fourteenthone == keyfour || fourteenthone == keyfive)
								{
									fourteenright = 2;
									if (fourteenthone == 'a')
										adone = 2;
									if (fourteenthone == 'b')
										bdone = 2;
									if (fourteenthone == 'c')
										cdone = 2;
									if (fourteenthone == 'd')
										ddone = 2;
									if (fourteenthone == 'e')
										edone = 2;
									if (fourteenthone == 'f')
										fdone = 2;
									if (fourteenthone == 'g')
										gdone = 2;
									if (fourteenthone == 'h')
										hdone = 2;
									if (fourteenthone == 'i')
										idone = 2;
									if (fourteenthone == 'j')
										jdone = 2;
									if (fourteenthone == 'k')
										kdone = 2;
									if (fourteenthone == 'l')
										ldone = 2;
									if (fourteenthone == 'm')
										mdone = 2;
									if (fourteenthone == 'n')
										ndone = 2;
									if (fourteenthone == 'o')
										odone = 2;
									if (fourteenthone == 'p')
										pdone = 2;
									if (fourteenthone == 'q')
										qdone = 2;
									if (fourteenthone == 'r')
										rdone = 2;
									if (fourteenthone == 's')
										sdone = 2;
									if (fourteenthone == 't')
										tdone = 2;
									if (fourteenthone == 'u')
										udone = 2;
									if (fourteenthone == 'v')
										vdone = 2;
									if (fourteenthone == 'w')
										wdone = 2;
									if (fourteenthone == 'x')
										xdone = 2;
									if (fourteenthone == 'y')
										ydone = 2;
									if (fourteenthone == 'z')
										zdone = 2;

								}
								else
								{
									fourteenright = 0;
									if (fourteenthone == 'a')
										adone = 3;
									if (fourteenthone == 'b')
										bdone = 3;
									if (fourteenthone == 'c')
										cdone = 3;
									if (fourteenthone == 'd')
										ddone = 3;
									if (fourteenthone == 'e')
										edone = 3;
									if (fourteenthone == 'f')
										fdone = 3;
									if (fourteenthone == 'g')
										gdone = 3;
									if (fourteenthone == 'h')
										hdone = 3;
									if (fourteenthone == 'i')
										idone = 3;
									if (fourteenthone == 'j')
										jdone = 3;
									if (fourteenthone == 'k')
										kdone = 3;
									if (fourteenthone == 'l')
										ldone = 3;
									if (fourteenthone == 'm')
										mdone = 3;
									if (fourteenthone == 'n')
										ndone = 3;
									if (fourteenthone == 'o')
										odone = 3;
									if (fourteenthone == 'p')
										pdone = 3;
									if (fourteenthone == 'q')
										qdone = 3;
									if (fourteenthone == 'r')
										rdone = 3;
									if (fourteenthone == 's')
										sdone = 3;
									if (fourteenthone == 't')
										tdone = 3;
									if (fourteenthone == 'u')
										udone = 3;
									if (fourteenthone == 'v')
										vdone = 3;
									if (fourteenthone == 'w')
										wdone = 3;
									if (fourteenthone == 'x')
										xdone = 3;
									if (fourteenthone == 'y')
										ydone = 3;
									if (fourteenthone == 'z')
										zdone = 3;
								}
									////////////////////////////////////////////////////////////////////

									if (fifteenthone == answer_list.at(4))
									{
										fifteenright = 1;
										if (fifteenthone == 'a')
											adone = 1;
										if (fifteenthone == 'b')
											bdone = 1;
										if (fifteenthone == 'c')
											cdone = 1;
										if (fifteenthone == 'd')
											ddone = 1;
										if (fifteenthone == 'e')
											edone = 1;
										if (fifteenthone == 'f')
											fdone = 1;
										if (fifteenthone == 'g')
											gdone = 1;
										if (fifteenthone == 'h')
											hdone = 1;
										if (fifteenthone == 'i')
											idone = 1;
										if (fifteenthone == 'j')
											jdone = 1;
										if (fifteenthone == 'k')
											kdone = 1;
										if (fifteenthone == 'l')
											ldone = 1;
										if (fifteenthone == 'm')
											mdone = 1;
										if (fifteenthone == 'n')
											ndone = 1;
										if (fifteenthone == 'o')
											odone = 1;
										if (fifteenthone == 'p')
											pdone = 1;
										if (fifteenthone == 'q')
											qdone = 1;
										if (fifteenthone == 'r')
											rdone = 1;
										if (fifteenthone == 's')
											sdone = 1;
										if (fifteenthone == 't')
											tdone = 1;
										if (fifteenthone == 'u')
											udone = 1;
										if (fifteenthone == 'v')
											vdone = 1;
										if (fifteenthone == 'w')
											wdone = 1;
										if (fifteenthone == 'x')
											xdone = 1;
										if (fifteenthone == 'y')
											ydone = 1;
										if (fifteenthone == 'z')
											zdone = 1;
									}
									else if (fifteenthone == keyone || fifteenthone == keytwo || fifteenthone == keythree || fifteenthone == keyfour || fifteenthone == keyfive)
									{
										fifteenright = 2;
										if (fifteenthone == 'a')
											adone = 2;
										if (fifteenthone == 'b')
											bdone = 2;
										if (fifteenthone == 'c')
											cdone = 2;
										if (fifteenthone == 'd')
											ddone = 2;
										if (fifteenthone == 'e')
											edone = 2;
										if (fifteenthone == 'f')
											fdone = 2;
										if (fifteenthone == 'g')
											gdone = 2;
										if (fifteenthone == 'h')
											hdone = 2;
										if (fifteenthone == 'i')
											idone = 2;
										if (fifteenthone == 'j')
											jdone = 2;
										if (fifteenthone == 'k')
											kdone = 2;
										if (fifteenthone == 'l')
											ldone = 2;
										if (fifteenthone == 'm')
											mdone = 2;
										if (fifteenthone == 'n')
											ndone = 2;
										if (fifteenthone == 'o')
											odone = 2;
										if (fifteenthone == 'p')
											pdone = 2;
										if (fifteenthone == 'q')
											qdone = 2;
										if (fifteenthone == 'r')
											rdone = 2;
										if (fifteenthone == 's')
											sdone = 2;
										if (fifteenthone == 't')
											tdone = 2;
										if (fifteenthone == 'u')
											udone = 2;
										if (fifteenthone == 'v')
											vdone = 2;
										if (fifteenthone == 'w')
											wdone = 2;
										if (fifteenthone == 'x')
											xdone = 2;
										if (fifteenthone == 'y')
											ydone = 2;
										if (fifteenthone == 'z')
											zdone = 2;

									}
									else
										fifteenright = 0;
										if (fifteenthone == 'a')
											adone = 3;
										if (fifteenthone == 'b')
											bdone = 3;
										if (fifteenthone == 'c')
											cdone = 3;
										if (fifteenthone == 'd')
											ddone = 3;
										if (fifteenthone == 'e')
											edone = 3;
										if (fifteenthone == 'f')
											fdone = 3;
										if (fifteenthone == 'g')
											gdone = 3;
										if (fifteenthone == 'h')
											hdone = 3;
										if (fifteenthone == 'i')
											idone = 3;
										if (fifteenthone == 'j')
											jdone = 3;
										if (fifteenthone == 'k')
											kdone = 3;
										if (fifteenthone == 'l')
											ldone = 3;
										if (fifteenthone == 'm')
											mdone = 3;
										if (fifteenthone == 'n')
											ndone = 3;
										if (fifteenthone == 'o')
											odone = 3;
										if (fifteenthone == 'p')
											pdone = 3;
										if (fifteenthone == 'q')
											qdone = 3;
										if (fifteenthone == 'r')
											rdone = 3;
										if (fifteenthone == 's')
											sdone = 3;
										if (fifteenthone == 't')
											tdone = 3;
										if (fifteenthone == 'u')
											udone = 3;
										if (fifteenthone == 'v')
											vdone = 3;
										if (fifteenthone == 'w')
											wdone = 3;
										if (fifteenthone == 'x')
											xdone = 3;
										if (fifteenthone == 'y')
											ydone = 3;
										if (fifteenthone == 'z')
											zdone = 3;
								
							
								std::cout << answer << std::endl;
							
								past_guess_three_letter_one.setString(past_guess3[0]);
								past_guess_three_letter_two.setString(past_guess3[1]);
								past_guess_three_letter_three.setString(past_guess3[2]);
								past_guess_three_letter_four.setString(past_guess3[3]);
								past_guess_three_letter_five.setString(past_guess3[4]);
								if (eleventhone == answer_list.at(0) && twelthone == answer_list.at(1) && thirteenthone == answer_list.at(2) && fourteenthone == answer_list.at(3) && fifteenthone == answer_list.at(4))
								{
									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;

								}
								guess->clear();
								++ticker;
								break;
							}
							if (ticker == 4)
							{
								past_guess4[0] = guess[0];
								past_guess4[1] = guess[1];
								past_guess4[2] = guess[2];
								past_guess4[3] = guess[3];
								past_guess4[4] = guess[4];
								guess->clear();
								std::cout << answer << std::endl << std::endl;
								char eleventhtwo{ past_guess4->at(0)};
								char twelthtwo{ past_guess4->at(1) };
								char thirteenthtwo{ past_guess4->at(2) };
								char fourteenthtwo{ past_guess4->at(3) };
								char fifteenthtwo{ past_guess4->at(4) };
							
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																////////////////////////////////////////////////////////////////////

								if (eleventhtwo == answer_list.at(0))
								{
									sixteenright = 1;
									if (eleventhtwo == 'a')
										adone = 1;
									if (eleventhtwo == 'b')
										bdone = 1;
									if (eleventhtwo == 'c')
										cdone = 1;
									if (eleventhtwo == 'd')
										ddone = 1;
									if (eleventhtwo == 'e')
										edone = 1;
									if (eleventhtwo == 'f')
										fdone = 1;
									if (eleventhtwo == 'g')
										gdone = 1;
									if (eleventhtwo == 'h')
										hdone = 1;
									if (eleventhtwo == 'i')
										idone = 1;
									if (eleventhtwo == 'j')
										jdone = 1;
									if (eleventhtwo == 'k')
										kdone = 1;
									if (eleventhtwo == 'l')
										ldone = 1;
									if (eleventhtwo == 'm')
										mdone = 1;
									if (eleventhtwo == 'n')
										ndone = 1;
									if (eleventhtwo == 'o')
										odone = 1;
									if (eleventhtwo == 'p')
										pdone = 1;
									if (eleventhtwo == 'q')
										qdone = 1;
									if (eleventhtwo == 'r')
										rdone = 1;
									if (eleventhtwo == 's')
										sdone = 1;
									if (eleventhtwo == 't')
										tdone = 1;
									if (eleventhtwo == 'u')
										udone = 1;
									if (eleventhtwo == 'v')
										vdone = 1;
									if (eleventhtwo == 'w')
										wdone = 1;
									if (eleventhtwo == 'x')
										xdone = 1;
									if (eleventhtwo == 'y')
										ydone = 1;
									if (eleventhtwo == 'z')
										zdone = 1;
								}
								else if (eleventhtwo == keyone || eleventhtwo == keytwo || eleventhtwo == keythree || eleventhtwo == keyfour || eleventhtwo == keyfive)
								{
									sixteenright = 2;
									if (eleventhtwo == 'a')
										adone = 2;
									if (eleventhtwo == 'b')
										bdone = 2;
									if (eleventhtwo == 'c')
										cdone = 2;
									if (eleventhtwo == 'd')
										ddone = 2;
									if (eleventhtwo == 'e')
										edone = 2;
									if (eleventhtwo == 'f')
										fdone = 2;
									if (eleventhtwo == 'g')
										gdone = 2;
									if (eleventhtwo == 'h')
										hdone = 2;
									if (eleventhtwo == 'i')
										idone = 2;
									if (eleventhtwo == 'j')
										jdone = 2;
									if (eleventhtwo == 'k')
										kdone = 2;
									if (eleventhtwo == 'l')
										ldone = 2;
									if (eleventhtwo == 'm')
										mdone = 2;
									if (eleventhtwo == 'n')
										ndone = 2;
									if (eleventhtwo == 'o')
										odone = 2;
									if (eleventhtwo == 'p')
										pdone = 2;
									if (eleventhtwo == 'q')
										qdone = 2;
									if (eleventhtwo == 'r')
										rdone = 2;
									if (eleventhtwo == 's')
										sdone = 2;
									if (eleventhtwo == 't')
										tdone = 2;
									if (eleventhtwo == 'u')
										udone = 2;
									if (eleventhtwo == 'v')
										vdone = 2;
									if (eleventhtwo == 'w')
										wdone = 2;
									if (eleventhtwo == 'x')
										xdone = 2;
									if (eleventhtwo == 'y')
										ydone = 2;
									if (eleventhtwo == 'z')
										zdone = 2;

								}
								else
									sixteenright = 0;
																////////////////////////////////////////////////////////////////////

								if (twelthtwo == answer_list.at(1))
								{
									seventeenright = 1;
									if (twelthtwo == 'a')
										adone = 1;
									if (twelthtwo == 'b')
										bdone = 1;
									if (twelthtwo == 'c')
										cdone = 1;
									if (twelthtwo == 'd')
										ddone = 1;
									if (twelthtwo == 'e')
										edone = 1;
									if (twelthtwo == 'f')
										fdone = 1;
									if (twelthtwo == 'g')
										gdone = 1;
									if (twelthtwo == 'h')
										hdone = 1;
									if (twelthtwo == 'i')
										idone = 1;
									if (twelthtwo == 'j')
										jdone = 1;
									if (twelthtwo == 'k')
										kdone = 1;
									if (twelthtwo == 'l')
										ldone = 1;
									if (twelthtwo == 'm')
										mdone = 1;
									if (twelthtwo == 'n')
										ndone = 1;
									if (twelthtwo == 'o')
										odone = 1;
									if (twelthtwo == 'p')
										pdone = 1;
									if (twelthtwo == 'q')
										qdone = 1;
									if (twelthtwo == 'r')
										rdone = 1;
									if (twelthtwo == 's')
										sdone = 1;
									if (twelthtwo == 't')
										tdone = 1;
									if (twelthtwo == 'u')
										udone = 1;
									if (twelthtwo == 'v')
										vdone = 1;
									if (twelthtwo == 'w')
										wdone = 1;
									if (twelthtwo == 'x')
										xdone = 1;
									if (twelthtwo == 'y')
										ydone = 1;
									if (twelthtwo == 'z')
										zdone = 1;
								}
								else if (twelthtwo == keyone || twelthtwo == keytwo || twelthtwo == keythree || twelthtwo == keyfour || twelthtwo == keyfive)
								{
									seventeenright = 2;
									if (twelthtwo == 'a')
										adone = 2;
									if (twelthtwo == 'b')
										bdone = 2;
									if (twelthtwo == 'c')
										cdone = 2;
									if (twelthtwo == 'd')
										ddone = 2;
									if (twelthtwo == 'e')
										edone = 2;
									if (twelthtwo == 'f')
										fdone = 2;
									if (twelthtwo == 'g')
										gdone = 2;
									if (twelthtwo == 'h')
										hdone = 2;
									if (twelthtwo == 'i')
										idone = 2;
									if (twelthtwo == 'j')
										jdone = 2;
									if (twelthtwo == 'k')
										kdone = 2;
									if (twelthtwo == 'l')
										ldone = 2;
									if (twelthtwo == 'm')
										mdone = 2;
									if (twelthtwo == 'n')
										ndone = 2;
									if (twelthtwo == 'o')
										odone = 2;
									if (twelthtwo == 'p')
										pdone = 2;
									if (twelthtwo == 'q')
										qdone = 2;
									if (twelthtwo == 'r')
										rdone = 2;
									if (twelthtwo == 's')
										sdone = 2;
									if (twelthtwo == 't')
										tdone = 2;
									if (twelthtwo == 'u')
										udone = 2;
									if (twelthtwo == 'v')
										vdone = 2;
									if (twelthtwo == 'w')
										wdone = 2;
									if (twelthtwo == 'x')
										xdone = 2;
									if (twelthtwo == 'y')
										ydone = 2;
									if (twelthtwo == 'z')
										zdone = 2;

								}
								else
									{
									seventeenright = 0;
									if (twelthtwo == 'a')
										adone = 3;
									if (twelthtwo == 'b')
										bdone = 3;
									if (twelthtwo == 'c')
										cdone = 3;
									if (twelthtwo == 'd')
										ddone = 3;
									if (twelthtwo == 'e')
										edone = 3;
									if (twelthtwo == 'f')
										fdone = 3;
									if (twelthtwo == 'g')
										gdone = 3;
									if (twelthtwo == 'h')
										hdone = 3;
									if (twelthtwo == 'i')
										idone = 3;
									if (twelthtwo == 'j')
										jdone = 3;
									if (twelthtwo == 'k')
										kdone = 3;
									if (twelthtwo == 'l')
										ldone = 3;
									if (twelthtwo == 'm')
										mdone = 3;
									if (twelthtwo == 'n')
										ndone = 3;
									if (twelthtwo == 'o')
										odone = 3;
									if (twelthtwo == 'p')
										pdone = 3;
									if (twelthtwo == 'q')
										qdone = 3;
									if (twelthtwo == 'r')
										rdone = 3;
									if (twelthtwo == 's')
										sdone = 3;
									if (twelthtwo == 't')
										tdone = 3;
									if (twelthtwo == 'u')
										udone = 3;
									if (twelthtwo == 'v')
										vdone = 3;
									if (twelthtwo == 'w')
										wdone = 3;
									if (twelthtwo == 'x')
										xdone = 3;
									if (twelthtwo == 'y')
										ydone = 3;
									if (twelthtwo == 'z')
										zdone = 3;
									}							
																////////////////////////////////////////////////////////////////////

								if (thirteenthtwo == answer_list.at(2))
								{
									eighteenright = 1;
									if (thirteenthtwo == 'a')
										adone = 1;
									if (thirteenthtwo == 'b')
										bdone = 1;
									if (thirteenthtwo == 'c')
										cdone = 1;
									if (thirteenthtwo == 'd')
										ddone = 1;
									if (thirteenthtwo == 'e')
										edone = 1;
									if (thirteenthtwo == 'f')
										fdone = 1;
									if (thirteenthtwo == 'g')
										gdone = 1;
									if (thirteenthtwo == 'h')
										hdone = 1;
									if (thirteenthtwo == 'i')
										idone = 1;
									if (thirteenthtwo == 'j')
										jdone = 1;
									if (thirteenthtwo == 'k')
										kdone = 1;
									if (thirteenthtwo == 'l')
										ldone = 1;
									if (thirteenthtwo == 'm')
										mdone = 1;
									if (thirteenthtwo == 'n')
										ndone = 1;
									if (thirteenthtwo == 'o')
										odone = 1;
									if (thirteenthtwo == 'p')
										pdone = 1;
									if (thirteenthtwo == 'q')
										qdone = 1;
									if (thirteenthtwo == 'r')
										rdone = 1;
									if (thirteenthtwo == 's')
										sdone = 1;
									if (thirteenthtwo == 't')
										tdone = 1;
									if (thirteenthtwo == 'u')
										udone = 1;
									if (thirteenthtwo == 'v')
										vdone = 1;
									if (thirteenthtwo == 'w')
										wdone = 1;
									if (thirteenthtwo == 'x')
										xdone = 1;
									if (thirteenthtwo == 'y')
										ydone = 1;
									if (thirteenthtwo == 'z')
										zdone = 1;
								}
								else if (thirteenthtwo == keyone || thirteenthtwo == keytwo || thirteenthtwo == keythree || thirteenthtwo == keyfour || thirteenthtwo == keyfive)
								{
									eighteenright = 2;
									if (thirteenthtwo == 'a')
										adone = 2;
									if (thirteenthtwo == 'b')
										bdone = 2;
									if (thirteenthtwo == 'c')
										cdone = 2;
									if (thirteenthtwo == 'd')
										ddone = 2;
									if (thirteenthtwo == 'e')
										edone = 2;
									if (thirteenthtwo == 'f')
										fdone = 2;
									if (thirteenthtwo == 'g')
										gdone = 2;
									if (thirteenthtwo == 'h')
										hdone = 2;
									if (thirteenthtwo == 'i')
										idone = 2;
									if (thirteenthtwo == 'j')
										jdone = 2;
									if (thirteenthtwo == 'k')
										kdone = 2;
									if (thirteenthtwo == 'l')
										ldone = 2;
									if (thirteenthtwo == 'm')
										mdone = 2;
									if (thirteenthtwo == 'n')
										ndone = 2;
									if (thirteenthtwo == 'o')
										odone = 2;
									if (thirteenthtwo == 'p')
										pdone = 2;
									if (thirteenthtwo == 'q')
										qdone = 2;
									if (thirteenthtwo == 'r')
										rdone = 2;
									if (thirteenthtwo == 's')
										sdone = 2;
									if (thirteenthtwo == 't')
										tdone = 2;
									if (thirteenthtwo == 'u')
										udone = 2;
									if (thirteenthtwo == 'v')
										vdone = 2;
									if (thirteenthtwo == 'w')
										wdone = 2;
									if (thirteenthtwo == 'x')
										xdone = 2;
									if (thirteenthtwo == 'y')
										ydone = 2;
									if (thirteenthtwo == 'z')
										zdone = 2;

								}
								else
									{
									eighteenright = 0;
									if (thirteenthtwo == 'a')
										adone = 3;
									if (thirteenthtwo == 'b')
										bdone = 3;
									if (thirteenthtwo == 'c')
										cdone = 3;
									if (thirteenthtwo == 'd')
										ddone = 3;
									if (thirteenthtwo == 'e')
										edone = 3;
									if (thirteenthtwo == 'f')
										fdone = 3;
									if (thirteenthtwo == 'g')
										gdone = 3;
									if (thirteenthtwo == 'h')
										hdone = 3;
									if (thirteenthtwo == 'i')
										idone = 3;
									if (thirteenthtwo == 'j')
										jdone = 3;
									if (thirteenthtwo == 'k')
										kdone = 3;
									if (thirteenthtwo == 'l')
										ldone = 3;
									if (thirteenthtwo == 'm')
										mdone = 3;
									if (thirteenthtwo == 'n')
										ndone = 3;
									if (thirteenthtwo == 'o')
										odone = 3;
									if (thirteenthtwo == 'p')
										pdone = 3;
									if (thirteenthtwo == 'q')
										qdone = 3;
									if (thirteenthtwo == 'r')
										rdone = 3;
									if (thirteenthtwo == 's')
										sdone = 3;
									if (thirteenthtwo == 't')
										tdone = 3;
									if (thirteenthtwo == 'u')
										udone = 3;
									if (thirteenthtwo == 'v')
										vdone = 3;
									if (thirteenthtwo == 'w')
										wdone = 3;
									if (thirteenthtwo == 'x')
										xdone = 3;
									if (thirteenthtwo == 'y')
										ydone = 3;
									if (thirteenthtwo == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (fourteenthtwo == answer_list.at(3))
								{
									nineteenright = 1;
									if (fourteenthtwo == 'a')
										adone = 1;
									if (fourteenthtwo == 'b')
										bdone = 1;
									if (fourteenthtwo == 'c')
										cdone = 1;
									if (fourteenthtwo == 'd')
										ddone = 1;
									if (fourteenthtwo == 'e')
										edone = 1;
									if (fourteenthtwo == 'f')
										fdone = 1;
									if (fourteenthtwo == 'g')
										gdone = 1;
									if (fourteenthtwo == 'h')
										hdone = 1;
									if (fourteenthtwo == 'i')
										idone = 1;
									if (fourteenthtwo == 'j')
										jdone = 1;
									if (fourteenthtwo == 'k')
										kdone = 1;
									if (fourteenthtwo == 'l')
										ldone = 1;
									if (fourteenthtwo == 'm')
										mdone = 1;
									if (fourteenthtwo == 'n')
										ndone = 1;
									if (fourteenthtwo == 'o')
										odone = 1;
									if (fourteenthtwo == 'p')
										pdone = 1;
									if (fourteenthtwo == 'q')
										qdone = 1;
									if (fourteenthtwo == 'r')
										rdone = 1;
									if (fourteenthtwo == 's')
										sdone = 1;
									if (fourteenthtwo == 't')
										tdone = 1;
									if (fourteenthtwo == 'u')
										udone = 1;
									if (fourteenthtwo == 'v')
										vdone = 1;
									if (fourteenthtwo == 'w')
										wdone = 1;
									if (fourteenthtwo == 'x')
										xdone = 1;
									if (fourteenthtwo == 'y')
										ydone = 1;
									if (fourteenthtwo == 'z')
										zdone = 1;
								}
								else if (fourteenthtwo == keyone || fourteenthtwo == keytwo || fourteenthtwo == keythree || fourteenthtwo == keyfour || fourteenthtwo == keyfive)
								{
									nineteenright = 2;
									if (fourteenthtwo == 'a')
										adone = 2;
									if (fourteenthtwo == 'b')
										bdone = 2;
									if (fourteenthtwo == 'c')
										cdone = 2;
									if (fourteenthtwo == 'd')
										ddone = 2;
									if (fourteenthtwo == 'e')
										edone = 2;
									if (fourteenthtwo == 'f')
										fdone = 2;
									if (fourteenthtwo == 'g')
										gdone = 2;
									if (fourteenthtwo == 'h')
										hdone = 2;
									if (fourteenthtwo == 'i')
										idone = 2;
									if (fourteenthtwo == 'j')
										jdone = 2;
									if (fourteenthtwo == 'k')
										kdone = 2;
									if (fourteenthtwo == 'l')
										ldone = 2;
									if (fourteenthtwo == 'm')
										mdone = 2;
									if (fourteenthtwo == 'n')
										ndone = 2;
									if (fourteenthtwo == 'o')
										odone = 2;
									if (fourteenthtwo == 'p')
										pdone = 2;
									if (fourteenthtwo == 'q')
										qdone = 2;
									if (fourteenthtwo == 'r')
										rdone = 2;
									if (fourteenthtwo == 's')
										sdone = 2;
									if (fourteenthtwo == 't')
										tdone = 2;
									if (fourteenthtwo == 'u')
										udone = 2;
									if (fourteenthtwo == 'v')
										vdone = 2;
									if (fourteenthtwo == 'w')
										wdone = 2;
									if (fourteenthtwo == 'x')
										xdone = 2;
									if (fourteenthtwo == 'y')
										ydone = 2;
									if (fourteenthtwo == 'z')
										zdone = 2;

								}
								else
									{
									nineteenright = 0;
									if (fourteenthtwo == 'a')
										adone = 3;
									if (fourteenthtwo == 'b')
										bdone = 3;
									if (fourteenthtwo == 'c')
										cdone = 3;
									if (fourteenthtwo == 'd')
										ddone = 3;
									if (fourteenthtwo == 'e')
										edone = 3;
									if (fourteenthtwo == 'f')
										fdone = 3;
									if (fourteenthtwo == 'g')
										gdone = 3;
									if (fourteenthtwo == 'h')
										hdone = 3;
									if (fourteenthtwo == 'i')
										idone = 3;
									if (fourteenthtwo == 'j')
										jdone = 3;
									if (fourteenthtwo == 'k')
										kdone = 3;
									if (fourteenthtwo == 'l')
										ldone = 3;
									if (fourteenthtwo == 'm')
										mdone = 3;
									if (fourteenthtwo == 'n')
										ndone = 3;
									if (fourteenthtwo == 'o')
										odone = 3;
									if (fourteenthtwo == 'p')
										pdone = 3;
									if (fourteenthtwo == 'q')
										qdone = 3;
									if (fourteenthtwo == 'r')
										rdone = 3;
									if (fourteenthtwo == 's')
										sdone = 3;
									if (fourteenthtwo == 't')
										tdone = 3;
									if (fourteenthtwo == 'u')
										udone = 3;
									if (fourteenthtwo == 'v')
										vdone = 3;
									if (fourteenthtwo == 'w')
										wdone = 3;
									if (fourteenthtwo == 'x')
										xdone = 3;
									if (fourteenthtwo == 'y')
										ydone = 3;
									if (fourteenthtwo == 'z')
										zdone = 3;
									}															
																////////////////////////////////////////////////////////////////////

								if (fifteenthtwo == answer_list.at(4))
								{
									twentyright = 1;
									if (fifteenthtwo == 'a')
										adone = 1;
									if (fifteenthtwo == 'b')
										bdone = 1;
									if (fifteenthtwo == 'c')
										cdone = 1;
									if (fifteenthtwo == 'd')
										ddone = 1;
									if (fifteenthtwo == 'e')
										edone = 1;
									if (fifteenthtwo == 'f')
										fdone = 1;
									if (fifteenthtwo == 'g')
										gdone = 1;
									if (fifteenthtwo == 'h')
										hdone = 1;
									if (fifteenthtwo == 'i')
										idone = 1;
									if (fifteenthtwo == 'j')
										jdone = 1;
									if (fifteenthtwo == 'k')
										kdone = 1;
									if (fifteenthtwo == 'l')
										ldone = 1;
									if (fifteenthtwo == 'm')
										mdone = 1;
									if (fifteenthtwo == 'n')
										ndone = 1;
									if (fifteenthtwo == 'o')
										odone = 1;
									if (fifteenthtwo == 'p')
										pdone = 1;
									if (fifteenthtwo == 'q')
										qdone = 1;
									if (fifteenthtwo == 'r')
										rdone = 1;
									if (fifteenthtwo == 's')
										sdone = 1;
									if (fifteenthtwo == 't')
										tdone = 1;
									if (fifteenthtwo == 'u')
										udone = 1;
									if (fifteenthtwo == 'v')
										vdone = 1;
									if (fifteenthtwo == 'w')
										wdone = 1;
									if (fifteenthtwo == 'x')
										xdone = 1;
									if (fifteenthtwo == 'y')
										ydone = 1;
									if (fifteenthtwo == 'z')
										zdone = 1;
								}
								else if (fifteenthtwo == keyone || fifteenthtwo == keytwo || fifteenthtwo == keythree || fifteenthtwo == keyfour || fifteenthtwo == keyfive)
								{
									twentyright = 2;
									if (fifteenthtwo == 'a')
										adone = 2;
									if (fifteenthtwo == 'b')
										bdone = 2;
									if (fifteenthtwo == 'c')
										cdone = 2;
									if (fifteenthtwo == 'd')
										ddone = 2;
									if (fifteenthtwo == 'e')
										edone = 2;
									if (fifteenthtwo == 'f')
										fdone = 2;
									if (fifteenthtwo == 'g')
										gdone = 2;
									if (fifteenthtwo == 'h')
										hdone = 2;
									if (fifteenthtwo == 'i')
										idone = 2;
									if (fifteenthtwo == 'j')
										jdone = 2;
									if (fifteenthtwo == 'k')
										kdone = 2;
									if (fifteenthtwo == 'l')
										ldone = 2;
									if (fifteenthtwo == 'm')
										mdone = 2;
									if (fifteenthtwo == 'n')
										ndone = 2;
									if (fifteenthtwo == 'o')
										odone = 2;
									if (fifteenthtwo == 'p')
										pdone = 2;
									if (fifteenthtwo == 'q')
										qdone = 2;
									if (fifteenthtwo == 'r')
										rdone = 2;
									if (fifteenthtwo == 's')
										sdone = 2;
									if (fifteenthtwo == 't')
										tdone = 2;
									if (fifteenthtwo == 'u')
										udone = 2;
									if (fifteenthtwo == 'v')
										vdone = 2;
									if (fifteenthtwo == 'w')
										wdone = 2;
									if (fifteenthtwo == 'x')
										xdone = 2;
									if (fifteenthtwo == 'y')
										ydone = 2;
									if (fifteenthtwo == 'z')
										zdone = 2;

								}
								else
									{
									twentyright = 0;
									if (fifteenthtwo == 'a')
										adone = 3;
									if (fifteenthtwo == 'b')
										bdone = 3;
									if (fifteenthtwo == 'c')
										cdone = 3;
									if (fifteenthtwo == 'd')
										ddone = 3;
									if (fifteenthtwo == 'e')
										edone = 3;
									if (fifteenthtwo == 'f')
										fdone = 3;
									if (fifteenthtwo == 'g')
										gdone = 3;
									if (fifteenthtwo == 'h')
										hdone = 3;
									if (fifteenthtwo == 'i')
										idone = 3;
									if (fifteenthtwo == 'j')
										jdone = 3;
									if (fifteenthtwo == 'k')
										kdone = 3;
									if (fifteenthtwo == 'l')
										ldone = 3;
									if (fifteenthtwo == 'm')
										mdone = 3;
									if (fifteenthtwo == 'n')
										ndone = 3;
									if (fifteenthtwo == 'o')
										odone = 3;
									if (fifteenthtwo == 'p')
										pdone = 3;
									if (fifteenthtwo == 'q')
										qdone = 3;
									if (fifteenthtwo == 'r')
										rdone = 3;
									if (fifteenthtwo == 's')
										sdone = 3;
									if (fifteenthtwo == 't')
										tdone = 3;
									if (fifteenthtwo == 'u')
										udone = 3;
									if (fifteenthtwo == 'v')
										vdone = 3;
									if (fifteenthtwo == 'w')
										wdone = 3;
									if (fifteenthtwo == 'x')
										xdone = 3;
									if (fifteenthtwo == 'y')
										ydone = 3;
									if (fifteenthtwo == 'z')
										zdone = 3;
									}
								
								
																
								
								
								
								
								
								
							
								std::cout << answer << std::endl;
							
								past_guess_four_letter_one.setString(past_guess4[0]);
								past_guess_four_letter_two.setString(past_guess4[1]);
								past_guess_four_letter_three.setString(past_guess4[2]);
								past_guess_four_letter_four.setString(past_guess4[3]);
								past_guess_four_letter_five.setString(past_guess4[4]);
								if (eleventhtwo == answer_list.at(0) && twelthtwo == answer_list.at(1) && thirteenthtwo == answer_list.at(2) && fourteenthtwo == answer_list.at(3) && fifteenthtwo == answer_list.at(4))
								{

									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;
								}
								guess->clear();
								++ticker;
								break;
							}
							if (ticker == 5)
							{
								past_guess5[0] = guess[0];
								past_guess5[1] = guess[1];
								past_guess5[2] = guess[2];
								past_guess5[3] = guess[3];
								past_guess5[4] = guess[4];
								guess->clear();
								std::cout << answer << std::endl << std::endl;
								char elevenththree{ past_guess5->at(0)};
								char twelththree{ past_guess5->at(1) };
								char thirteenththree{ past_guess5->at(2) };
								char fourteenththree{ past_guess5->at(3) };
								char fifteenththree{ past_guess5->at(4) };
															////////////////////////////////////////////////////////////////////

								if (elevenththree == answer_list.at(0))
								{
									twentyoneright = 1;
									if (elevenththree == 'a')
										adone = 1;
									if (elevenththree == 'b')
										bdone = 1;
									if (elevenththree == 'c')
										cdone = 1;
									if (elevenththree == 'd')
										ddone = 1;
									if (elevenththree == 'e')
										edone = 1;
									if (elevenththree == 'f')
										fdone = 1;
									if (elevenththree == 'g')
										gdone = 1;
									if (elevenththree == 'h')
										hdone = 1;
									if (elevenththree == 'i')
										idone = 1;
									if (elevenththree == 'j')
										jdone = 1;
									if (elevenththree == 'k')
										kdone = 1;
									if (elevenththree == 'l')
										ldone = 1;
									if (elevenththree == 'm')
										mdone = 1;
									if (elevenththree == 'n')
										ndone = 1;
									if (elevenththree == 'o')
										odone = 1;
									if (elevenththree == 'p')
										pdone = 1;
									if (elevenththree == 'q')
										qdone = 1;
									if (elevenththree == 'r')
										rdone = 1;
									if (elevenththree == 's')
										sdone = 1;
									if (elevenththree == 't')
										tdone = 1;
									if (elevenththree == 'u')
										udone = 1;
									if (elevenththree == 'v')
										vdone = 1;
									if (elevenththree == 'w')
										wdone = 1;
									if (elevenththree == 'x')
										xdone = 1;
									if (elevenththree == 'y')
										ydone = 1;
									if (elevenththree == 'z')
										zdone = 1;
								}
								else if (elevenththree == keyone || elevenththree == keytwo || elevenththree == keythree || elevenththree == keyfour || elevenththree == keyfive)
								{
									twentyoneright = 2;
									if (elevenththree == 'a')
										adone = 2;
									if (elevenththree == 'b')
										bdone = 2;
									if (elevenththree == 'c')
										cdone = 2;
									if (elevenththree == 'd')
										ddone = 2;
									if (elevenththree == 'e')
										edone = 2;
									if (elevenththree == 'f')
										fdone = 2;
									if (elevenththree == 'g')
										gdone = 2;
									if (elevenththree == 'h')
										hdone = 2;
									if (elevenththree == 'i')
										idone = 2;
									if (elevenththree == 'j')
										jdone = 2;
									if (elevenththree == 'k')
										kdone = 2;
									if (elevenththree == 'l')
										ldone = 2;
									if (elevenththree == 'm')
										mdone = 2;
									if (elevenththree == 'n')
										ndone = 2;
									if (elevenththree == 'o')
										odone = 2;
									if (elevenththree == 'p')
										pdone = 2;
									if (elevenththree == 'q')
										qdone = 2;
									if (elevenththree == 'r')
										rdone = 2;
									if (elevenththree == 's')
										sdone = 2;
									if (elevenththree == 't')
										tdone = 2;
									if (elevenththree == 'u')
										udone = 2;
									if (elevenththree == 'v')
										vdone = 2;
									if (elevenththree == 'w')
										wdone = 2;
									if (elevenththree == 'x')
										xdone = 2;
									if (elevenththree == 'y')
										ydone = 2;
									if (elevenththree == 'z')
										zdone = 2;

								}
								else
									{
									twentyoneright = 0;
									if (elevenththree == 'a')
										adone = 3;
									if (elevenththree == 'b')
										bdone = 3;
									if (elevenththree == 'c')
										cdone = 3;
									if (elevenththree == 'd')
										ddone = 3;
									if (elevenththree == 'e')
										edone = 3;
									if (elevenththree == 'f')
										fdone = 3;
									if (elevenththree == 'g')
										gdone = 3;
									if (elevenththree == 'h')
										hdone = 3;
									if (elevenththree == 'i')
										idone = 3;
									if (elevenththree == 'j')
										jdone = 3;
									if (elevenththree == 'k')
										kdone = 3;
									if (elevenththree == 'l')
										ldone = 3;
									if (elevenththree == 'm')
										mdone = 3;
									if (elevenththree == 'n')
										ndone = 3;
									if (elevenththree == 'o')
										odone = 3;
									if (elevenththree == 'p')
										pdone = 3;
									if (elevenththree == 'q')
										qdone = 3;
									if (elevenththree == 'r')
										rdone = 3;
									if (elevenththree == 's')
										sdone = 3;
									if (elevenththree == 't')
										tdone = 3;
									if (elevenththree == 'u')
										udone = 3;
									if (elevenththree == 'v')
										vdone = 3;
									if (elevenththree == 'w')
										wdone = 3;
									if (elevenththree == 'x')
										xdone = 3;
									if (elevenththree == 'y')
										ydone = 3;
									if (elevenththree == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (twelththree == answer_list.at(1))
								{
									twentytworight = 1;
									if (twelththree == 'a')
										adone = 1;
									if (twelththree == 'b')
										bdone = 1;
									if (twelththree == 'c')
										cdone = 1;
									if (twelththree == 'd')
										ddone = 1;
									if (twelththree == 'e')
										edone = 1;
									if (twelththree == 'f')
										fdone = 1;
									if (twelththree == 'g')
										gdone = 1;
									if (twelththree == 'h')
										hdone = 1;
									if (twelththree == 'i')
										idone = 1;
									if (twelththree == 'j')
										jdone = 1;
									if (twelththree == 'k')
										kdone = 1;
									if (twelththree == 'l')
										ldone = 1;
									if (twelththree == 'm')
										mdone = 1;
									if (twelththree == 'n')
										ndone = 1;
									if (twelththree == 'o')
										odone = 1;
									if (twelththree == 'p')
										pdone = 1;
									if (twelththree == 'q')
										qdone = 1;
									if (twelththree == 'r')
										rdone = 1;
									if (twelththree == 's')
										sdone = 1;
									if (twelththree == 't')
										tdone = 1;
									if (twelththree == 'u')
										udone = 1;
									if (twelththree == 'v')
										vdone = 1;
									if (twelththree == 'w')
										wdone = 1;
									if (twelththree == 'x')
										xdone = 1;
									if (twelththree == 'y')
										ydone = 1;
									if (twelththree == 'z')
										zdone = 1;
								}
								else if (twelththree == keyone || twelththree == keytwo || twelththree == keythree || twelththree == keyfour || twelththree == keyfive)
								{
									twentytworight = 2;
									if (twelththree == 'a')
										adone = 2;
									if (twelththree == 'b')
										bdone = 2;
									if (twelththree == 'c')
										cdone = 2;
									if (twelththree == 'd')
										ddone = 2;
									if (twelththree == 'e')
										edone = 2;
									if (twelththree == 'f')
										fdone = 2;
									if (twelththree == 'g')
										gdone = 2;
									if (twelththree == 'h')
										hdone = 2;
									if (twelththree == 'i')
										idone = 2;
									if (twelththree == 'j')
										jdone = 2;
									if (twelththree == 'k')
										kdone = 2;
									if (twelththree == 'l')
										ldone = 2;
									if (twelththree == 'm')
										mdone = 2;
									if (twelththree == 'n')
										ndone = 2;
									if (twelththree == 'o')
										odone = 2;
									if (twelththree == 'p')
										pdone = 2;
									if (twelththree == 'q')
										qdone = 2;
									if (twelththree == 'r')
										rdone = 2;
									if (twelththree == 's')
										sdone = 2;
									if (twelththree == 't')
										tdone = 2;
									if (twelththree == 'u')
										udone = 2;
									if (twelththree == 'v')
										vdone = 2;
									if (twelththree == 'w')
										wdone = 2;
									if (twelththree == 'x')
										xdone = 2;
									if (twelththree == 'y')
										ydone = 2;
									if (twelththree == 'z')
										zdone = 2;

								}
								else
									{
									twentytworight = 0;
									if (twelththree == 'a')
										adone = 3;
									if (twelththree == 'b')
										bdone = 3;
									if (twelththree == 'c')
										cdone = 3;
									if (twelththree == 'd')
										ddone = 3;
									if (twelththree == 'e')
										edone = 3;
									if (twelththree == 'f')
										fdone = 3;
									if (twelththree == 'g')
										gdone = 3;
									if (twelththree == 'h')
										hdone = 3;
									if (twelththree == 'i')
										idone = 3;
									if (twelththree == 'j')
										jdone = 3;
									if (twelththree == 'k')
										kdone = 3;
									if (twelththree == 'l')
										ldone = 3;
									if (twelththree == 'm')
										mdone = 3;
									if (twelththree == 'n')
										ndone = 3;
									if (twelththree == 'o')
										odone = 3;
									if (twelththree == 'p')
										pdone = 3;
									if (twelththree == 'q')
										qdone = 3;
									if (twelththree == 'r')
										rdone = 3;
									if (twelththree == 's')
										sdone = 3;
									if (twelththree == 't')
										tdone = 3;
									if (twelththree == 'u')
										udone = 3;
									if (twelththree == 'v')
										vdone = 3;
									if (twelththree == 'w')
										wdone = 3;
									if (twelththree == 'x')
										xdone = 3;
									if (twelththree == 'y')
										ydone = 3;
									if (twelththree == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (thirteenththree == answer_list.at(2))
								{
									twentythreeright = 1;
									if (thirteenththree == 'a')
										adone = 1;
									if (thirteenththree == 'b')
										bdone = 1;
									if (thirteenththree == 'c')
										cdone = 1;
									if (thirteenththree == 'd')
										ddone = 1;
									if (thirteenththree == 'e')
										edone = 1;
									if (thirteenththree == 'f')
										fdone = 1;
									if (thirteenththree == 'g')
										gdone = 1;
									if (thirteenththree == 'h')
										hdone = 1;
									if (thirteenththree == 'i')
										idone = 1;
									if (thirteenththree == 'j')
										jdone = 1;
									if (thirteenththree == 'k')
										kdone = 1;
									if (thirteenththree == 'l')
										ldone = 1;
									if (thirteenththree == 'm')
										mdone = 1;
									if (thirteenththree == 'n')
										ndone = 1;
									if (thirteenththree == 'o')
										odone = 1;
									if (thirteenththree == 'p')
										pdone = 1;
									if (thirteenththree == 'q')
										qdone = 1;
									if (thirteenththree == 'r')
										rdone = 1;
									if (thirteenththree == 's')
										sdone = 1;
									if (thirteenththree == 't')
										tdone = 1;
									if (thirteenththree == 'u')
										udone = 1;
									if (thirteenththree == 'v')
										vdone = 1;
									if (thirteenththree == 'w')
										wdone = 1;
									if (thirteenththree == 'x')
										xdone = 1;
									if (thirteenththree == 'y')
										ydone = 1;
									if (thirteenththree == 'z')
										zdone = 1;
								}
								else if (thirteenththree == keyone || thirteenththree == keytwo || thirteenththree == keythree || thirteenththree == keyfour || thirteenththree == keyfive)
								{
									twentythreeright = 2;
									if (thirteenththree == 'a')
										adone = 2;
									if (thirteenththree == 'b')
										bdone = 2;
									if (thirteenththree == 'c')
										cdone = 2;
									if (thirteenththree == 'd')
										ddone = 2;
									if (thirteenththree == 'e')
										edone = 2;
									if (thirteenththree == 'f')
										fdone = 2;
									if (thirteenththree == 'g')
										gdone = 2;
									if (thirteenththree == 'h')
										hdone = 2;
									if (thirteenththree == 'i')
										idone = 2;
									if (thirteenththree == 'j')
										jdone = 2;
									if (thirteenththree == 'k')
										kdone = 2;
									if (thirteenththree == 'l')
										ldone = 2;
									if (thirteenththree == 'm')
										mdone = 2;
									if (thirteenththree == 'n')
										ndone = 2;
									if (thirteenththree == 'o')
										odone = 2;
									if (thirteenththree == 'p')
										pdone = 2;
									if (thirteenththree == 'q')
										qdone = 2;
									if (thirteenththree == 'r')
										rdone = 2;
									if (thirteenththree == 's')
										sdone = 2;
									if (thirteenththree == 't')
										tdone = 2;
									if (thirteenththree == 'u')
										udone = 2;
									if (thirteenththree == 'v')
										vdone = 2;
									if (thirteenththree == 'w')
										wdone = 2;
									if (thirteenththree == 'x')
										xdone = 2;
									if (thirteenththree == 'y')
										ydone = 2;
									if (thirteenththree == 'z')
										zdone = 2;

								}
								else
									{
									twentythreeright = 0;
									if (thirteenththree == 'a')
										adone = 3;
									if (thirteenththree == 'b')
										bdone = 3;
									if (thirteenththree == 'c')
										cdone = 3;
									if (thirteenththree == 'd')
										ddone = 3;
									if (thirteenththree == 'e')
										edone = 3;
									if (thirteenththree == 'f')
										fdone = 3;
									if (thirteenththree == 'g')
										gdone = 3;
									if (thirteenththree == 'h')
										hdone = 3;
									if (thirteenththree == 'i')
										idone = 3;
									if (thirteenththree == 'j')
										jdone = 3;
									if (thirteenththree == 'k')
										kdone = 3;
									if (thirteenththree == 'l')
										ldone = 3;
									if (thirteenththree == 'm')
										mdone = 3;
									if (thirteenththree == 'n')
										ndone = 3;
									if (thirteenththree == 'o')
										odone = 3;
									if (thirteenththree == 'p')
										pdone = 3;
									if (thirteenththree == 'q')
										qdone = 3;
									if (thirteenththree == 'r')
										rdone = 3;
									if (thirteenththree == 's')
										sdone = 3;
									if (thirteenththree == 't')
										tdone = 3;
									if (thirteenththree == 'u')
										udone = 3;
									if (thirteenththree == 'v')
										vdone = 3;
									if (thirteenththree == 'w')
										wdone = 3;
									if (thirteenththree == 'x')
										xdone = 3;
									if (thirteenththree == 'y')
										ydone = 3;
									if (thirteenththree == 'z')
										zdone = 3;
									}							
																////////////////////////////////////////////////////////////////////

								if (fourteenththree == answer_list.at(3))
								{
									twentyfourright = 1;
									if (fourteenththree == 'a')
										adone = 1;
									if (fourteenththree == 'b')
										bdone = 1;
									if (fourteenththree == 'c')
										cdone = 1;
									if (fourteenththree == 'd')
										ddone = 1;
									if (fourteenththree == 'e')
										edone = 1;
									if (fourteenththree == 'f')
										fdone = 1;
									if (fourteenththree == 'g')
										gdone = 1;
									if (fourteenththree == 'h')
										hdone = 1;
									if (fourteenththree == 'i')
										idone = 1;
									if (fourteenththree == 'j')
										jdone = 1;
									if (fourteenththree == 'k')
										kdone = 1;
									if (fourteenththree == 'l')
										ldone = 1;
									if (fourteenththree == 'm')
										mdone = 1;
									if (fourteenththree == 'n')
										ndone = 1;
									if (fourteenththree == 'o')
										odone = 1;
									if (fourteenththree == 'p')
										pdone = 1;
									if (fourteenththree == 'q')
										qdone = 1;
									if (fourteenththree == 'r')
										rdone = 1;
									if (fourteenththree == 's')
										sdone = 1;
									if (fourteenththree == 't')
										tdone = 1;
									if (fourteenththree == 'u')
										udone = 1;
									if (fourteenththree == 'v')
										vdone = 1;
									if (fourteenththree == 'w')
										wdone = 1;
									if (fourteenththree == 'x')
										xdone = 1;
									if (fourteenththree == 'y')
										ydone = 1;
									if (fourteenththree == 'z')
										zdone = 1;
								}
								else if (fourteenththree == keyone || fourteenththree == keytwo || fourteenththree == keythree || fourteenththree == keyfour || fourteenththree == keyfive)
								{
									twentyfourright = 2;
									if (fourteenththree == 'a')
										adone = 2;
									if (fourteenththree == 'b')
										bdone = 2;
									if (fourteenththree == 'c')
										cdone = 2;
									if (fourteenththree == 'd')
										ddone = 2;
									if (fourteenththree == 'e')
										edone = 2;
									if (fourteenththree == 'f')
										fdone = 2;
									if (fourteenththree == 'g')
										gdone = 2;
									if (fourteenththree == 'h')
										hdone = 2;
									if (fourteenththree == 'i')
										idone = 2;
									if (fourteenththree == 'j')
										jdone = 2;
									if (fourteenththree == 'k')
										kdone = 2;
									if (fourteenththree == 'l')
										ldone = 2;
									if (fourteenththree == 'm')
										mdone = 2;
									if (fourteenththree == 'n')
										ndone = 2;
									if (fourteenththree == 'o')
										odone = 2;
									if (fourteenththree == 'p')
										pdone = 2;
									if (fourteenththree == 'q')
										qdone = 2;
									if (fourteenththree == 'r')
										rdone = 2;
									if (fourteenththree == 's')
										sdone = 2;
									if (fourteenththree == 't')
										tdone = 2;
									if (fourteenththree == 'u')
										udone = 2;
									if (fourteenththree == 'v')
										vdone = 2;
									if (fourteenththree == 'w')
										wdone = 2;
									if (fourteenththree == 'x')
										xdone = 2;
									if (fourteenththree == 'y')
										ydone = 2;
									if (fourteenththree == 'z')
										zdone = 2;

								}
								else
									{
									twentyfourright = 0;
									if (fourteenththree == 'a')
										adone = 3;
									if (fourteenththree == 'b')
										bdone = 3;
									if (fourteenththree == 'c')
										cdone = 3;
									if (fourteenththree == 'd')
										ddone = 3;
									if (fourteenththree == 'e')
										edone = 3;
									if (fourteenththree == 'f')
										fdone = 3;
									if (fourteenththree == 'g')
										gdone = 3;
									if (fourteenththree == 'h')
										hdone = 3;
									if (fourteenththree == 'i')
										idone = 3;
									if (fourteenththree == 'j')
										jdone = 3;
									if (fourteenththree == 'k')
										kdone = 3;
									if (fourteenththree == 'l')
										ldone = 3;
									if (fourteenththree == 'm')
										mdone = 3;
									if (fourteenththree == 'n')
										ndone = 3;
									if (fourteenththree == 'o')
										odone = 3;
									if (fourteenththree == 'p')
										pdone = 3;
									if (fourteenththree == 'q')
										qdone = 3;
									if (fourteenththree == 'r')
										rdone = 3;
									if (fourteenththree == 's')
										sdone = 3;
									if (fourteenththree == 't')
										tdone = 3;
									if (fourteenththree == 'u')
										udone = 3;
									if (fourteenththree == 'v')
										vdone = 3;
									if (fourteenththree == 'w')
										wdone = 3;
									if (fourteenththree == 'x')
										xdone = 3;
									if (fourteenththree == 'y')
										ydone = 3;
									if (fourteenththree == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (fifteenththree == answer_list.at(4))
								{
									twentyfiveright = 1;
									if (fifteenththree == 'a')
										adone = 1;
									if (fifteenththree == 'b')
										bdone = 1;
									if (fifteenththree == 'c')
										cdone = 1;
									if (fifteenththree == 'd')
										ddone = 1;
									if (fifteenththree == 'e')
										edone = 1;
									if (fifteenththree == 'f')
										fdone = 1;
									if (fifteenththree == 'g')
										gdone = 1;
									if (fifteenththree == 'h')
										hdone = 1;
									if (fifteenththree == 'i')
										idone = 1;
									if (fifteenththree == 'j')
										jdone = 1;
									if (fifteenththree == 'k')
										kdone = 1;
									if (fifteenththree == 'l')
										ldone = 1;
									if (fifteenththree == 'm')
										mdone = 1;
									if (fifteenththree == 'n')
										ndone = 1;
									if (fifteenththree == 'o')
										odone = 1;
									if (fifteenththree == 'p')
										pdone = 1;
									if (fifteenththree == 'q')
										qdone = 1;
									if (fifteenththree == 'r')
										rdone = 1;
									if (fifteenththree == 's')
										sdone = 1;
									if (fifteenththree == 't')
										tdone = 1;
									if (fifteenththree == 'u')
										udone = 1;
									if (fifteenththree == 'v')
										vdone = 1;
									if (fifteenththree == 'w')
										wdone = 1;
									if (fifteenththree == 'x')
										xdone = 1;
									if (fifteenththree == 'y')
										ydone = 1;
									if (fifteenththree == 'z')
										zdone = 1;
								}
								else if (fifteenththree == keyone || fifteenththree == keytwo || fifteenththree == keythree || fifteenththree == keyfour || fifteenththree == keyfive)
								{
									twentyfiveright = 2;
									if (fifteenththree == 'a')
										adone = 2;
									if (fifteenththree == 'b')
										bdone = 2;
									if (fifteenththree == 'c')
										cdone = 2;
									if (fifteenththree == 'd')
										ddone = 2;
									if (fifteenththree == 'e')
										edone = 2;
									if (fifteenththree == 'f')
										fdone = 2;
									if (fifteenththree == 'g')
										gdone = 2;
									if (fifteenththree == 'h')
										hdone = 2;
									if (fifteenththree == 'i')
										idone = 2;
									if (fifteenththree == 'j')
										jdone = 2;
									if (fifteenththree == 'k')
										kdone = 2;
									if (fifteenththree == 'l')
										ldone = 2;
									if (fifteenththree == 'm')
										mdone = 2;
									if (fifteenththree == 'n')
										ndone = 2;
									if (fifteenththree == 'o')
										odone = 2;
									if (fifteenththree == 'p')
										pdone = 2;
									if (fifteenththree == 'q')
										qdone = 2;
									if (fifteenththree == 'r')
										rdone = 2;
									if (fifteenththree == 's')
										sdone = 2;
									if (fifteenththree == 't')
										tdone = 2;
									if (fifteenththree == 'u')
										udone = 2;
									if (fifteenththree == 'v')
										vdone = 2;
									if (fifteenththree == 'w')
										wdone = 2;
									if (fifteenththree == 'x')
										xdone = 2;
									if (fifteenththree == 'y')
										ydone = 2;
									if (fifteenththree == 'z')
										zdone = 2;

								}
								else
									{
									twentyfiveright = 0;
									if (fifteenththree == 'a')
										adone = 3;
									if (fifteenththree == 'b')
										bdone = 3;
									if (fifteenththree == 'c')
										cdone = 3;
									if (fifteenththree == 'd')
										ddone = 3;
									if (fifteenththree == 'e')
										edone = 3;
									if (fifteenththree == 'f')
										fdone = 3;
									if (fifteenththree == 'g')
										gdone = 3;
									if (fifteenththree == 'h')
										hdone = 3;
									if (fifteenththree == 'i')
										idone = 3;
									if (fifteenththree == 'j')
										jdone = 3;
									if (fifteenththree == 'k')
										kdone = 3;
									if (fifteenththree == 'l')
										ldone = 3;
									if (fifteenththree == 'm')
										mdone = 3;
									if (fifteenththree == 'n')
										ndone = 3;
									if (fifteenththree == 'o')
										odone = 3;
									if (fifteenththree == 'p')
										pdone = 3;
									if (fifteenththree == 'q')
										qdone = 3;
									if (fifteenththree == 'r')
										rdone = 3;
									if (fifteenththree == 's')
										sdone = 3;
									if (fifteenththree == 't')
										tdone = 3;
									if (fifteenththree == 'u')
										udone = 3;
									if (fifteenththree == 'v')
										vdone = 3;
									if (fifteenththree == 'w')
										wdone = 3;
									if (fifteenththree == 'x')
										xdone = 3;
									if (fifteenththree == 'y')
										ydone = 3;
									if (fifteenththree == 'z')
										zdone = 3;
									}
								
								

								
																
								
								
							
							
								std::cout << answer << std::endl;
							
								past_guess_five_letter_one.setString(past_guess5[0]);
								past_guess_five_letter_two.setString(past_guess5[1]);
								past_guess_five_letter_three.setString(past_guess5[2]);
								past_guess_five_letter_four.setString(past_guess5[3]);
								past_guess_five_letter_five.setString(past_guess5[4]);
								if (elevenththree == answer_list.at(0) && twelththree == answer_list.at(1) && thirteenththree == answer_list.at(2) && fourteenththree == answer_list.at(3) && fifteenththree == answer_list.at(4))
								{
									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;

								}
								guess->clear();
								++ticker;
								break;
							}
							if (ticker == 6)
							{
								past_guess6[0] = guess[0];
								past_guess6[1] = guess[1];
								past_guess6[2] = guess[2];
								past_guess6[3] = guess[3];
								past_guess6[4] = guess[4];
								guess->clear();
								std::cout << answer << std::endl << std::endl;
								char eleventhfour{ past_guess6->at(0)};
								char twelthfour{ past_guess6->at(1) };
								char thirteenthfour{ past_guess6->at(2) };
								char fourteenthfour{ past_guess6->at(3) };
								char fifteenthfour{ past_guess6->at(4) };
							
								///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																////////////////////////////////////////////////////////////////////

								if (eleventhfour == answer_list.at(0))
								{
									twentysixright = 1;
									if (eleventhfour == 'a')
										adone = 1;
									if (eleventhfour == 'b')
										bdone = 1;
									if (eleventhfour == 'c')
										cdone = 1;
									if (eleventhfour == 'd')
										ddone = 1;
									if (eleventhfour == 'e')
										edone = 1;
									if (eleventhfour == 'f')
										fdone = 1;
									if (eleventhfour == 'g')
										gdone = 1;
									if (eleventhfour == 'h')
										hdone = 1;
									if (eleventhfour == 'i')
										idone = 1;
									if (eleventhfour == 'j')
										jdone = 1;
									if (eleventhfour == 'k')
										kdone = 1;
									if (eleventhfour == 'l')
										ldone = 1;
									if (eleventhfour == 'm')
										mdone = 1;
									if (eleventhfour == 'n')
										ndone = 1;
									if (eleventhfour == 'o')
										odone = 1;
									if (eleventhfour == 'p')
										pdone = 1;
									if (eleventhfour == 'q')
										qdone = 1;
									if (eleventhfour == 'r')
										rdone = 1;
									if (eleventhfour == 's')
										sdone = 1;
									if (eleventhfour == 't')
										tdone = 1;
									if (eleventhfour == 'u')
										udone = 1;
									if (eleventhfour == 'v')
										vdone = 1;
									if (eleventhfour == 'w')
										wdone = 1;
									if (eleventhfour == 'x')
										xdone = 1;
									if (eleventhfour == 'y')
										ydone = 1;
									if (eleventhfour == 'z')
										zdone = 1;
								}
								else if (eleventhfour == keyone || eleventhfour == keytwo || eleventhfour == keythree || eleventhfour == keyfour || eleventhfour == keyfive)
								{
									twentysixright = 2;
									if (eleventhfour == 'a')
										adone = 2;
									if (eleventhfour == 'b')
										bdone = 2;
									if (eleventhfour == 'c')
										cdone = 2;
									if (eleventhfour == 'd')
										ddone = 2;
									if (eleventhfour == 'e')
										edone = 2;
									if (eleventhfour == 'f')
										fdone = 2;
									if (eleventhfour == 'g')
										gdone = 2;
									if (eleventhfour == 'h')
										hdone = 2;
									if (eleventhfour == 'i')
										idone = 2;
									if (eleventhfour == 'j')
										jdone = 2;
									if (eleventhfour == 'k')
										kdone = 2;
									if (eleventhfour == 'l')
										ldone = 2;
									if (eleventhfour == 'm')
										mdone = 2;
									if (eleventhfour == 'n')
										ndone = 2;
									if (eleventhfour == 'o')
										odone = 2;
									if (eleventhfour == 'p')
										pdone = 2;
									if (eleventhfour == 'q')
										qdone = 2;
									if (eleventhfour == 'r')
										rdone = 2;
									if (eleventhfour == 's')
										sdone = 2;
									if (eleventhfour == 't')
										tdone = 2;
									if (eleventhfour == 'u')
										udone = 2;
									if (eleventhfour == 'v')
										vdone = 2;
									if (eleventhfour == 'w')
										wdone = 2;
									if (eleventhfour == 'x')
										xdone = 2;
									if (eleventhfour == 'y')
										ydone = 2;
									if (eleventhfour == 'z')
										zdone = 2;

								}
								else
									{
									twentysixright = 0;
									if (eleventhfour == 'a')
										adone = 3;
									if (eleventhfour == 'b')
										bdone = 3;
									if (eleventhfour == 'c')
										cdone = 3;
									if (eleventhfour == 'd')
										ddone = 3;
									if (eleventhfour == 'e')
										edone = 3;
									if (eleventhfour == 'f')
										fdone = 3;
									if (eleventhfour == 'g')
										gdone = 3;
									if (eleventhfour == 'h')
										hdone = 3;
									if (eleventhfour == 'i')
										idone = 3;
									if (eleventhfour == 'j')
										jdone = 3;
									if (eleventhfour == 'k')
										kdone = 3;
									if (eleventhfour == 'l')
										ldone = 3;
									if (eleventhfour == 'm')
										mdone = 3;
									if (eleventhfour == 'n')
										ndone = 3;
									if (eleventhfour == 'o')
										odone = 3;
									if (eleventhfour == 'p')
										pdone = 3;
									if (eleventhfour == 'q')
										qdone = 3;
									if (eleventhfour == 'r')
										rdone = 3;
									if (eleventhfour == 's')
										sdone = 3;
									if (eleventhfour == 't')
										tdone = 3;
									if (eleventhfour == 'u')
										udone = 3;
									if (eleventhfour == 'v')
										vdone = 3;
									if (eleventhfour == 'w')
										wdone = 3;
									if (eleventhfour == 'x')
										xdone = 3;
									if (eleventhfour == 'y')
										ydone = 3;
									if (eleventhfour == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (twelthfour == answer_list.at(1))
								{
									twentysevenright = 1;
									if (twelthfour == 'a')
										adone = 1;
									if (twelthfour == 'b')
										bdone = 1;
									if (twelthfour == 'c')
										cdone = 1;
									if (twelthfour == 'd')
										ddone = 1;
									if (twelthfour == 'e')
										edone = 1;
									if (twelthfour == 'f')
										fdone = 1;
									if (twelthfour == 'g')
										gdone = 1;
									if (twelthfour == 'h')
										hdone = 1;
									if (twelthfour == 'i')
										idone = 1;
									if (twelthfour == 'j')
										jdone = 1;
									if (twelthfour == 'k')
										kdone = 1;
									if (twelthfour == 'l')
										ldone = 1;
									if (twelthfour == 'm')
										mdone = 1;
									if (twelthfour == 'n')
										ndone = 1;
									if (twelthfour == 'o')
										odone = 1;
									if (twelthfour == 'p')
										pdone = 1;
									if (twelthfour == 'q')
										qdone = 1;
									if (twelthfour == 'r')
										rdone = 1;
									if (twelthfour == 's')
										sdone = 1;
									if (twelthfour == 't')
										tdone = 1;
									if (twelthfour == 'u')
										udone = 1;
									if (twelthfour == 'v')
										vdone = 1;
									if (twelthfour == 'w')
										wdone = 1;
									if (twelthfour == 'x')
										xdone = 1;
									if (twelthfour == 'y')
										ydone = 1;
									if (twelthfour == 'z')
										zdone = 1;
								}
								else if (twelthfour == keyone || twelthfour == keytwo || twelthfour == keythree || twelthfour == keyfour || twelthfour == keyfive)
								{
									twentysevenright = 2;
									if (twelthfour == 'a')
										adone = 2;
									if (twelthfour == 'b')
										bdone = 2;
									if (twelthfour == 'c')
										cdone = 2;
									if (twelthfour == 'd')
										ddone = 2;
									if (twelthfour == 'e')
										edone = 2;
									if (twelthfour == 'f')
										fdone = 2;
									if (twelthfour == 'g')
										gdone = 2;
									if (twelthfour == 'h')
										hdone = 2;
									if (twelthfour == 'i')
										idone = 2;
									if (twelthfour == 'j')
										jdone = 2;
									if (twelthfour == 'k')
										kdone = 2;
									if (twelthfour == 'l')
										ldone = 2;
									if (twelthfour == 'm')
										mdone = 2;
									if (twelthfour == 'n')
										ndone = 2;
									if (twelthfour == 'o')
										odone = 2;
									if (twelthfour == 'p')
										pdone = 2;
									if (twelthfour == 'q')
										qdone = 2;
									if (twelthfour == 'r')
										rdone = 2;
									if (twelthfour == 's')
										sdone = 2;
									if (twelthfour == 't')
										tdone = 2;
									if (twelthfour == 'u')
										udone = 2;
									if (twelthfour == 'v')
										vdone = 2;
									if (twelthfour == 'w')
										wdone = 2;
									if (twelthfour == 'x')
										xdone = 2;
									if (twelthfour == 'y')
										ydone = 2;
									if (twelthfour == 'z')
										zdone = 2;

								}
								else
									{
									twentysevenright = 0;
									if (twelthfour == 'a')
										adone = 3;
									if (twelthfour == 'b')
										bdone = 3;
									if (twelthfour == 'c')
										cdone = 3;
									if (twelthfour == 'd')
										ddone = 3;
									if (twelthfour == 'e')
										edone = 3;
									if (twelthfour == 'f')
										fdone = 3;
									if (twelthfour == 'g')
										gdone = 3;
									if (twelthfour == 'h')
										hdone = 3;
									if (twelthfour == 'i')
										idone = 3;
									if (twelthfour == 'j')
										jdone = 3;
									if (twelthfour == 'k')
										kdone = 3;
									if (twelthfour == 'l')
										ldone = 3;
									if (twelthfour == 'm')
										mdone = 3;
									if (twelthfour == 'n')
										ndone = 3;
									if (twelthfour == 'o')
										odone = 3;
									if (twelthfour == 'p')
										pdone = 3;
									if (twelthfour == 'q')
										qdone = 3;
									if (twelthfour == 'r')
										rdone = 3;
									if (twelthfour == 's')
										sdone = 3;
									if (twelthfour == 't')
										tdone = 3;
									if (twelthfour == 'u')
										udone = 3;
									if (twelthfour == 'v')
										vdone = 3;
									if (twelthfour == 'w')
										wdone = 3;
									if (twelthfour == 'x')
										xdone = 3;
									if (twelthfour == 'y')
										ydone = 3;
									if (twelthfour == 'z')
										zdone = 3;
									}
																////////////////////////////////////////////////////////////////////

								if (thirteenthfour == answer_list.at(2))
								{
									twentyeightright = 1;
									if (thirteenthfour == 'a')
										adone = 1;
									if (thirteenthfour == 'b')
										bdone = 1;
									if (thirteenthfour == 'c')
										cdone = 1;
									if (thirteenthfour == 'd')
										ddone = 1;
									if (thirteenthfour == 'e')
										edone = 1;
									if (thirteenthfour == 'f')
										fdone = 1;
									if (thirteenthfour == 'g')
										gdone = 1;
									if (thirteenthfour == 'h')
										hdone = 1;
									if (thirteenthfour == 'i')
										idone = 1;
									if (thirteenthfour == 'j')
										jdone = 1;
									if (thirteenthfour == 'k')
										kdone = 1;
									if (thirteenthfour == 'l')
										ldone = 1;
									if (thirteenthfour == 'm')
										mdone = 1;
									if (thirteenthfour == 'n')
										ndone = 1;
									if (thirteenthfour == 'o')
										odone = 1;
									if (thirteenthfour == 'p')
										pdone = 1;
									if (thirteenthfour == 'q')
										qdone = 1;
									if (thirteenthfour == 'r')
										rdone = 1;
									if (thirteenthfour == 's')
										sdone = 1;
									if (thirteenthfour == 't')
										tdone = 1;
									if (thirteenthfour == 'u')
										udone = 1;
									if (thirteenthfour == 'v')
										vdone = 1;
									if (thirteenthfour == 'w')
										wdone = 1;
									if (thirteenthfour == 'x')
										xdone = 1;
									if (thirteenthfour == 'y')
										ydone = 1;
									if (thirteenthfour == 'z')
										zdone = 1;
								}
								else if (thirteenthfour == keyone || thirteenthfour == keytwo || thirteenthfour == keythree || thirteenthfour == keyfour || thirteenthfour == keyfive)
								{
									twentyeightright = 2;
									if (thirteenthfour == 'a')
										adone = 2;
									if (thirteenthfour == 'b')
										bdone = 2;
									if (thirteenthfour == 'c')
										cdone = 2;
									if (thirteenthfour == 'd')
										ddone = 2;
									if (thirteenthfour == 'e')
										edone = 2;
									if (thirteenthfour == 'f')
										fdone = 2;
									if (thirteenthfour == 'g')
										gdone = 2;
									if (thirteenthfour == 'h')
										hdone = 2;
									if (thirteenthfour == 'i')
										idone = 2;
									if (thirteenthfour == 'j')
										jdone = 2;
									if (thirteenthfour == 'k')
										kdone = 2;
									if (thirteenthfour == 'l')
										ldone = 2;
									if (thirteenthfour == 'm')
										mdone = 2;
									if (thirteenthfour == 'n')
										ndone = 2;
									if (thirteenthfour == 'o')
										odone = 2;
									if (thirteenthfour == 'p')
										pdone = 2;
									if (thirteenthfour == 'q')
										qdone = 2;
									if (thirteenthfour == 'r')
										rdone = 2;
									if (thirteenthfour == 's')
										sdone = 2;
									if (thirteenthfour == 't')
										tdone = 2;
									if (thirteenthfour == 'u')
										udone = 2;
									if (thirteenthfour == 'v')
										vdone = 2;
									if (thirteenthfour == 'w')
										wdone = 2;
									if (thirteenthfour == 'x')
										xdone = 2;
									if (thirteenthfour == 'y')
										ydone = 2;
									if (thirteenthfour == 'z')
										zdone = 2;

								}
								else
									{
									twentyeightright = 0;
									if (thirteenthfour == 'a')
										adone = 3;
									if (thirteenthfour == 'b')
										bdone = 3;
									if (thirteenthfour == 'c')
										cdone = 3;
									if (thirteenthfour == 'd')
										ddone = 3;
									if (thirteenthfour == 'e')
										edone = 3;
									if (thirteenthfour == 'f')
										fdone = 3;
									if (thirteenthfour == 'g')
										gdone = 3;
									if (thirteenthfour == 'h')
										hdone = 3;
									if (thirteenthfour == 'i')
										idone = 3;
									if (thirteenthfour == 'j')
										jdone = 3;
									if (thirteenthfour == 'k')
										kdone = 3;
									if (thirteenthfour == 'l')
										ldone = 3;
									if (thirteenthfour == 'm')
										mdone = 3;
									if (thirteenthfour == 'n')
										ndone = 3;
									if (thirteenthfour == 'o')
										odone = 3;
									if (thirteenthfour == 'p')
										pdone = 3;
									if (thirteenthfour == 'q')
										qdone = 3;
									if (thirteenthfour == 'r')
										rdone = 3;
									if (thirteenthfour == 's')
										sdone = 3;
									if (thirteenthfour == 't')
										tdone = 3;
									if (thirteenthfour == 'u')
										udone = 3;
									if (thirteenthfour == 'v')
										vdone = 3;
									if (thirteenthfour == 'w')
										wdone = 3;
									if (thirteenthfour == 'x')
										xdone = 3;
									if (thirteenthfour == 'y')
										ydone = 3;
									if (thirteenthfour == 'z')
										zdone = 3;
									}							
																////////////////////////////////////////////////////////////////////

								if (fourteenthfour == answer_list.at(3))
								{
									twentynineright = 1;
									if (fourteenthfour == 'a')
										adone = 1;
									if (fourteenthfour == 'b')
										bdone = 1;
									if (fourteenthfour == 'c')
										cdone = 1;
									if (fourteenthfour == 'd')
										ddone = 1;
									if (fourteenthfour == 'e')
										edone = 1;
									if (fourteenthfour == 'f')
										fdone = 1;
									if (fourteenthfour == 'g')
										gdone = 1;
									if (fourteenthfour == 'h')
										hdone = 1;
									if (fourteenthfour == 'i')
										idone = 1;
									if (fourteenthfour == 'j')
										jdone = 1;
									if (fourteenthfour == 'k')
										kdone = 1;
									if (fourteenthfour == 'l')
										ldone = 1;
									if (fourteenthfour == 'm')
										mdone = 1;
									if (fourteenthfour == 'n')
										ndone = 1;
									if (fourteenthfour == 'o')
										odone = 1;
									if (fourteenthfour == 'p')
										pdone = 1;
									if (fourteenthfour == 'q')
										qdone = 1;
									if (fourteenthfour == 'r')
										rdone = 1;
									if (fourteenthfour == 's')
										sdone = 1;
									if (fourteenthfour == 't')
										tdone = 1;
									if (fourteenthfour == 'u')
										udone = 1;
									if (fourteenthfour == 'v')
										vdone = 1;
									if (fourteenthfour == 'w')
										wdone = 1;
									if (fourteenthfour == 'x')
										xdone = 1;
									if (fourteenthfour == 'y')
										ydone = 1;
									if (fourteenthfour == 'z')
										zdone = 1;
								}
								else if (fourteenthfour == keyone || fourteenthfour == keytwo || fourteenthfour == keythree || fourteenthfour == keyfour || fourteenthfour == keyfive)
								{
									twentynineright = 2;
									if (fourteenthfour == 'a')
										adone = 2;
									if (fourteenthfour == 'b')
										bdone = 2;
									if (fourteenthfour == 'c')
										cdone = 2;
									if (fourteenthfour == 'd')
										ddone = 2;
									if (fourteenthfour == 'e')
										edone = 2;
									if (fourteenthfour == 'f')
										fdone = 2;
									if (fourteenthfour == 'g')
										gdone = 2;
									if (fourteenthfour == 'h')
										hdone = 2;
									if (fourteenthfour == 'i')
										idone = 2;
									if (fourteenthfour == 'j')
										jdone = 2;
									if (fourteenthfour == 'k')
										kdone = 2;
									if (fourteenthfour == 'l')
										ldone = 2;
									if (fourteenthfour == 'm')
										mdone = 2;
									if (fourteenthfour == 'n')
										ndone = 2;
									if (fourteenthfour == 'o')
										odone = 2;
									if (fourteenthfour == 'p')
										pdone = 2;
									if (fourteenthfour == 'q')
										qdone = 2;
									if (fourteenthfour == 'r')
										rdone = 2;
									if (fourteenthfour == 's')
										sdone = 2;
									if (fourteenthfour == 't')
										tdone = 2;
									if (fourteenthfour == 'u')
										udone = 2;
									if (fourteenthfour == 'v')
										vdone = 2;
									if (fourteenthfour == 'w')
										wdone = 2;
									if (fourteenthfour == 'x')
										xdone = 2;
									if (fourteenthfour == 'y')
										ydone = 2;
									if (fourteenthfour == 'z')
										zdone = 2;

								}
								else
									{
									twentynineright = 0;
									if (fourteenthfour == 'a')
										adone = 3;
									if (fourteenthfour == 'b')
										bdone = 3;
									if (fourteenthfour == 'c')
										cdone = 3;
									if (fourteenthfour == 'd')
										ddone = 3;
									if (fourteenthfour == 'e')
										edone = 3;
									if (fourteenthfour == 'f')
										fdone = 3;
									if (fourteenthfour == 'g')
										gdone = 3;
									if (fourteenthfour == 'h')
										hdone = 3;
									if (fourteenthfour == 'i')
										idone = 3;
									if (fourteenthfour == 'j')
										jdone = 3;
									if (fourteenthfour == 'k')
										kdone = 3;
									if (fourteenthfour == 'l')
										ldone = 3;
									if (fourteenthfour == 'm')
										mdone = 3;
									if (fourteenthfour == 'n')
										ndone = 3;
									if (fourteenthfour == 'o')
										odone = 3;
									if (fourteenthfour == 'p')
										pdone = 3;
									if (fourteenthfour == 'q')
										qdone = 3;
									if (fourteenthfour == 'r')
										rdone = 3;
									if (fourteenthfour == 's')
										sdone = 3;
									if (fourteenthfour == 't')
										tdone = 3;
									if (fourteenthfour == 'u')
										udone = 3;
									if (fourteenthfour == 'v')
										vdone = 3;
									if (fourteenthfour == 'w')
										wdone = 3;
									if (fourteenthfour == 'x')
										xdone = 3;
									if (fourteenthfour == 'y')
										ydone = 3;
									if (fourteenthfour == 'z')
										zdone = 3;
									}							
																////////////////////////////////////////////////////////////////////

								if (fifteenthfour == answer_list.at(4))
								{
									thirtyright = 1;
									if (fifteenthfour == 'a')
										adone = 1;
									if (fifteenthfour == 'b')
										bdone = 1;
									if (fifteenthfour == 'c')
										cdone = 1;
									if (fifteenthfour == 'd')
										ddone = 1;
									if (fifteenthfour == 'e')
										edone = 1;
									if (fifteenthfour == 'f')
										fdone = 1;
									if (fifteenthfour == 'g')
										gdone = 1;
									if (fifteenthfour == 'h')
										hdone = 1;
									if (fifteenthfour == 'i')
										idone = 1;
									if (fifteenthfour == 'j')
										jdone = 1;
									if (fifteenthfour == 'k')
										kdone = 1;
									if (fifteenthfour == 'l')
										ldone = 1;
									if (fifteenthfour == 'm')
										mdone = 1;
									if (fifteenthfour == 'n')
										ndone = 1;
									if (fifteenthfour == 'o')
										odone = 1;
									if (fifteenthfour == 'p')
										pdone = 1;
									if (fifteenthfour == 'q')
										qdone = 1;
									if (fifteenthfour == 'r')
										rdone = 1;
									if (fifteenthfour == 's')
										sdone = 1;
									if (fifteenthfour == 't')
										tdone = 1;
									if (fifteenthfour == 'u')
										udone = 1;
									if (fifteenthfour == 'v')
										vdone = 1;
									if (fifteenthfour == 'w')
										wdone = 1;
									if (fifteenthfour == 'x')
										xdone = 1;
									if (fifteenthfour == 'y')
										ydone = 1;
									if (fifteenthfour == 'z')
										zdone = 1;
								}
								else if (fifteenthfour == keyone || fifteenthfour == keytwo || fifteenthfour == keythree || fifteenthfour == keyfour || fifteenthfour == keyfive)
								{
									thirtyright = 2;
									if (fifteenthfour == 'a')
										adone = 2;
									if (fifteenthfour == 'b')
										bdone = 2;
									if (fifteenthfour == 'c')
										cdone = 2;
									if (fifteenthfour == 'd')
										ddone = 2;
									if (fifteenthfour == 'e')
										edone = 2;
									if (fifteenthfour == 'f')
										fdone = 2;
									if (fifteenthfour == 'g')
										gdone = 2;
									if (fifteenthfour == 'h')
										hdone = 2;
									if (fifteenthfour == 'i')
										idone = 2;
									if (fifteenthfour == 'j')
										jdone = 2;
									if (fifteenthfour == 'k')
										kdone = 2;
									if (fifteenthfour == 'l')
										ldone = 2;
									if (fifteenthfour == 'm')
										mdone = 2;
									if (fifteenthfour == 'n')
										ndone = 2;
									if (fifteenthfour == 'o')
										odone = 2;
									if (fifteenthfour == 'p')
										pdone = 2;
									if (fifteenthfour == 'q')
										qdone = 2;
									if (fifteenthfour == 'r')
										rdone = 2;
									if (fifteenthfour == 's')
										sdone = 2;
									if (fifteenthfour == 't')
										tdone = 2;
									if (fifteenthfour == 'u')
										udone = 2;
									if (fifteenthfour == 'v')
										vdone = 2;
									if (fifteenthfour == 'w')
										wdone = 2;
									if (fifteenthfour == 'x')
										xdone = 2;
									if (fifteenthfour == 'y')
										ydone = 2;
									if (fifteenthfour == 'z')
										zdone = 2;

								}
								else
									{
									thirtyright = 0;
									if (fifteenthfour == 'a')
										adone = 3;
									if (fifteenthfour == 'b')
										bdone = 3;
									if (fifteenthfour == 'c')
										cdone = 3;
									if (fifteenthfour == 'd')
										ddone = 3;
									if (fifteenthfour == 'e')
										edone = 3;
									if (fifteenthfour == 'f')
										fdone = 3;
									if (fifteenthfour == 'g')
										gdone = 3;
									if (fifteenthfour == 'h')
										hdone = 3;
									if (fifteenthfour == 'i')
										idone = 3;
									if (fifteenthfour == 'j')
										jdone = 3;
									if (fifteenthfour == 'k')
										kdone = 3;
									if (fifteenthfour == 'l')
										ldone = 3;
									if (fifteenthfour == 'm')
										mdone = 3;
									if (fifteenthfour == 'n')
										ndone = 3;
									if (fifteenthfour == 'o')
										odone = 3;
									if (fifteenthfour == 'p')
										pdone = 3;
									if (fifteenthfour == 'q')
										qdone = 3;
									if (fifteenthfour == 'r')
										rdone = 3;
									if (fifteenthfour == 's')
										sdone = 3;
									if (fifteenthfour == 't')
										tdone = 3;
									if (fifteenthfour == 'u')
										udone = 3;
									if (fifteenthfour == 'v')
										vdone = 3;
									if (fifteenthfour == 'w')
										wdone = 3;
									if (fifteenthfour == 'x')
										xdone = 3;
									if (fifteenthfour == 'y')
										ydone = 3;
									if (fifteenthfour == 'z')
										zdone = 3;
									}
								
								
								
								
								
								
								
								
							
							
								std::cout << answer << std::endl;
							
								past_guess_six_letter_one.setString(past_guess6[0]);
								past_guess_six_letter_two.setString(past_guess6[1]);
								past_guess_six_letter_three.setString(past_guess6[2]);
								past_guess_six_letter_four.setString(past_guess6[3]);
								past_guess_six_letter_five.setString(past_guess6[4]);
								if (eleventhfour == answer_list.at(0) && twelthfour == answer_list.at(1) && thirteenthfour == answer_list.at(2) && fourteenthfour == answer_list.at(3) && fifteenthfour == answer_list.at(4))
								{
									ticker = 7;
									enterflag = 1;
									wordso = answer;
									break;

								}
								guess->clear();
								wordso = answer;
								enterflag = 1;
								ticker = 7;
								break;

							}// 
							//fucking a i'm an idiot. just use a monospace font dude, make it easy on yourself. good morning! (: 
							if (ticker == 7)
							{
								wordso = "*****";
								std::string past_guess1[5] = {};
								std::string past_guess2[5] = {};
								std::string past_guess3[5] = {};
								std::string past_guess4[5] = {};
								std::string past_guess5[5] = {};
								std::string past_guess6[5] = {};
								std::string box_rects[60] = {};
								std::string guess[5] = {};
								answer_list = {};
							
								//seed srand
							
							
								answer_list.clear();
							
								oneright = 0;
								tworight = 0;
								threeright = 0;
								fourright = 0;
								fiveright = 0;
								sixright = 0;
								sevenright = 0;
								eightright = 0;
								nineright = 0;
								tenright = 0;
								elevenright = 0;
								twelveright = 0;
								thirteenright = 0;
								fourteenright = 0;
								fifteenright = 0;
								sixteenright = 0;
								seventeenright = 0;
								eighteenright = 0;
								nineteenright = 0;
								twentyright = 0;
								twentyoneright = 0;
								twentytworight = 0;
								twentythreeright = 0;
								twentyfourright = 0;
								twentyfiveright = 0;
								twentysixright = 0;
								twentysevenright = 0;
								twentyeightright = 0;
								twentynineright = 0;
								thirtyright = 0;
								adone = 0;
								bdone = 0;
								cdone = 0;
								ddone = 0;
								edone = 0;
								fdone = 0;
								gdone = 0;
								hdone = 0;
								idone = 0;
								jdone = 0;
								kdone = 0;
								ldone = 0;
								mdone = 0;
								ndone = 0;
								odone = 0;
								pdone = 0;
								qdone = 0;
								rdone = 0;
								sdone = 0;
								tdone = 0;
								udone = 0;
								vdone = 0;
								wdone = 0;
								xdone = 0;
								ydone = 0;
								zdone = 0;
								ticker = 0;
								past_guess_one_letter_one.setString("");
								past_guess_one_letter_two.setString("");
								past_guess_one_letter_three.setString("");
								past_guess_one_letter_four.setString("");
								past_guess_one_letter_five.setString("");
								past_guess_two_letter_one.setString("");
								past_guess_two_letter_two.setString("");
								past_guess_two_letter_three.setString("");
								past_guess_two_letter_four.setString("");
								past_guess_two_letter_five.setString("");
								past_guess_three_letter_one.setString("");
								past_guess_three_letter_two.setString("");
								past_guess_three_letter_three.setString("");
								past_guess_three_letter_four.setString("");
								past_guess_three_letter_five.setString("");
								past_guess_four_letter_one.setString("");
								past_guess_four_letter_two.setString("");
								past_guess_four_letter_three.setString("");
								past_guess_four_letter_four.setString("");
								past_guess_four_letter_five.setString("");
								past_guess_five_letter_one.setString("");
								past_guess_five_letter_two.setString("");
								past_guess_five_letter_three.setString("");
								past_guess_five_letter_four.setString("");
								past_guess_five_letter_five.setString("");
								past_guess_six_letter_one.setString("");
								past_guess_six_letter_two.setString("");
								past_guess_six_letter_three.setString("");
								past_guess_six_letter_four.setString("");
								past_guess_six_letter_five.setString("");
							
							}
						}	
					}
					else
					{
						std::cout << "You must guess a five letter word!" << std::endl;
					}
				}
				if (ev.key.code == sf::Keyboard::Space)
					std::cout << guess[0] << guess[1] << guess[2] << guess[3] << guess[4] << guess[5] << std::endl;
				break;
            }
        }
        //clear
        window.clear(sf::Color(10,10,10));
        //draw
		std::string alphabet[40]{"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"};

		
		
		
		
		sf::Text textq;
		textq.setFont(font);
		textq.setString(alphabet[0]);
		textq.setCharacterSize(40);
		textq.setFillColor(sf::Color(100, 100, 100));
		textq.setPosition(sf::Vector2f(565, 210));

		sf::Text textw;
		textw.setFont(font);
		textw.setString(alphabet[1]);
		textw.setCharacterSize(40);
		textw.setFillColor(sf::Color(100, 100, 100));
		textw.setPosition(sf::Vector2f(630, 210));
		
		sf::Text texte;
		texte.setFont(font);
		texte.setString(alphabet[2]);
		texte.setCharacterSize(40);
		texte.setFillColor(sf::Color(100, 100, 100));
		texte.setPosition(sf::Vector2f(695, 210));

		sf::Text textr;
		textr.setFont(font);
		textr.setString(alphabet[3]);
		textr.setCharacterSize(40);
		textr.setFillColor(sf::Color(100, 100, 100));
		textr.setPosition(sf::Vector2f(760, 210));
		
		sf::Text textt;
		textt.setFont(font);
		textt.setString(alphabet[4]);
		textt.setCharacterSize(40);
		textt.setFillColor(sf::Color(100, 100, 100));
		textt.setPosition(sf::Vector2f(825, 210));
		
		sf::Text texty;
		texty.setFont(font);
		texty.setString(alphabet[5]);
		texty.setCharacterSize(40);
		texty.setFillColor(sf::Color(100, 100, 100));
		texty.setPosition(sf::Vector2f(893, 210));
		
		sf::Text textu;
		textu.setFont(font);
		textu.setString(alphabet[6]);
		textu.setCharacterSize(40);
		textu.setFillColor(sf::Color(100, 100, 100));
		textu.setPosition(sf::Vector2f(955, 210));
		
		sf::Text texti;
		texti.setFont(font);
		texti.setString(alphabet[7]);
		texti.setCharacterSize(40);
		texti.setFillColor(sf::Color(100, 100, 100));
		texti.setPosition(sf::Vector2f(1018, 210));
		
		sf::Text texto;
		texto.setFont(font);
		texto.setString(alphabet[8]);
		texto.setCharacterSize(40);
		texto.setFillColor(sf::Color(100, 100, 100));
		texto.setPosition(sf::Vector2f(1080, 210));
		
		sf::Text textp;
		textp.setFont(font);
		textp.setString(alphabet[9]);
		textp.setCharacterSize(40);
		textp.setFillColor(sf::Color(100, 100, 100));
		textp.setPosition(sf::Vector2f(1150, 210));

		sf::Text texta;
		texta.setFont(font);
		texta.setString(alphabet[10]);
		texta.setCharacterSize(40);
		texta.setFillColor(sf::Color(100, 100, 100));
		texta.setPosition(sf::Vector2f(595, 275));

		sf::Text texts;
		texts.setFont(font);
		texts.setString(alphabet[11]);
		texts.setCharacterSize(40);
		texts.setFillColor(sf::Color(100, 100, 100));
		texts.setPosition(sf::Vector2f(660, 275));

		sf::Text textd;
		textd.setFont(font);
		textd.setString(alphabet[12]);
		textd.setCharacterSize(40);
		textd.setFillColor(sf::Color(100, 100, 100));
		textd.setPosition(sf::Vector2f(725, 275));

		sf::Text textf;
		textf.setFont(font);
		textf.setString(alphabet[13]);
		textf.setCharacterSize(40);
		textf.setFillColor(sf::Color(100, 100, 100));
		textf.setPosition(sf::Vector2f(790, 275));

		sf::Text textg;
		textg.setFont(font);
		textg.setString(alphabet[14]);
		textg.setCharacterSize(40);
		textg.setFillColor(sf::Color(100, 100, 100));
		textg.setPosition(sf::Vector2f(855, 275));

		sf::Text texth;
		texth.setFont(font);
		texth.setString(alphabet[15]);
		texth.setCharacterSize(40);
		texth.setFillColor(sf::Color(100, 100, 100));
		texth.setPosition(sf::Vector2f(920, 275));

		sf::Text textj;
		textj.setFont(font);
		textj.setString(alphabet[16]);
		textj.setCharacterSize(40);
		textj.setFillColor(sf::Color(100, 100, 100));
		textj.setPosition(sf::Vector2f(985, 275));

		sf::Text textk;
		textk.setFont(font);
		textk.setString(alphabet[17]);
		textk.setCharacterSize(40);
		textk.setFillColor(sf::Color(100, 100, 100));
		textk.setPosition(sf::Vector2f(1050, 275));

		sf::Text textl;
		textl.setFont(font);
		textl.setString(alphabet[18]);
		textl.setCharacterSize(40);
		textl.setFillColor(sf::Color(100, 100, 100));
		textl.setPosition(sf::Vector2f(1115, 275));

		sf::Text textz;
		textz.setFont(font);
		textz.setString(alphabet[19]);
		textz.setCharacterSize(40);
		textz.setFillColor(sf::Color(100, 100, 100));
		textz.setPosition(sf::Vector2f(625, 345));

		sf::Text textx;
		textx.setFont(font);
		textx.setString(alphabet[20]);
		textx.setCharacterSize(40);
		textx.setFillColor(sf::Color(100, 100, 100));
		textx.setPosition(sf::Vector2f(690, 345));

		sf::Text textc;
		textc.setFont(font);
		textc.setString(alphabet[21]);
		textc.setCharacterSize(40);
		textc.setFillColor(sf::Color(100, 100, 100));
		textc.setPosition(sf::Vector2f(755, 345));

		sf::Text textv;
		textv.setFont(font);
		textv.setString(alphabet[22]);
		textv.setCharacterSize(40);
		textv.setFillColor(sf::Color(100, 100, 100));
		textv.setPosition(sf::Vector2f(820, 345));

		sf::Text textb;
		textb.setFont(font);
		textb.setString(alphabet[23]);
		textb.setCharacterSize(40);
		textb.setFillColor(sf::Color(100, 100, 100));
		textb.setPosition(sf::Vector2f(885, 345));

		sf::Text textn;
		textn.setFont(font);
		textn.setString(alphabet[24]);
		textn.setCharacterSize(40);
		textn.setFillColor(sf::Color(100, 100, 100));
		textn.setPosition(sf::Vector2f(950, 345));

		sf::Text textm;
		textm.setFont(font);
		textm.setString(alphabet[25]);
		textm.setCharacterSize(40);
		textm.setFillColor(sf::Color(100, 100, 100));
		textm.setPosition(sf::Vector2f(1015, 345));
		
		std::string wordsy{ "-your word is-" };
		sf::Text declarey;
		declarey.setFont(font);
		declarey.setString(wordsy);
		declarey.setCharacterSize(60);
		declarey.setFillColor(sf::Color(100, 100, 100));
		declarey.setPosition(sf::Vector2f(660, 405));
		
		
		sf::Text declareo;
		declareo.setFont(font);
		declareo.setString(wordso);
		declareo.setCharacterSize(120);
		declareo.setFillColor(sf::Color(100, 100, 100));
		declareo.setPosition(sf::Vector2f(720, 455));

		std::string pressenter{ "press enter to continue" };
		sf::Text press_enter;
		press_enter.setFont(font);
		press_enter.setString(pressenter);
		press_enter.setCharacterSize(60);
		press_enter.setFillColor(sf::Color(100, 100, 100));
		press_enter.setPosition(sf::Vector2f(525, 600));
		
		std::string titley{ "BOReDLE" };
		sf::Text titleh;
		titleh.setFont(font);
		titleh.setString(titley);
		titleh.setCharacterSize(190);
		titleh.setFillColor(sf::Color(100, 100, 100));
		titleh.setPosition(sf::Vector2f(535, 0));
		
		std::string versionnum{ "-daltonyx-v1.61" };
		sf::Text versnum;
		versnum.setFont(font);
		versnum.setString(versionnum);
		versnum.setCharacterSize(20);
		versnum.setFillColor(sf::Color(100, 100, 100));
		versnum.setPosition(sf::Vector2f(1097, 2));
		

		if (enterflag == 1)
			window.draw(press_enter);
		window.draw(versnum);
		window.draw(titleh);
		window.draw(declareo);
		window.draw(declarey);
		window.draw(keyq);
		window.draw(keyw);
		window.draw(keye);
		window.draw(keyr);
		window.draw(keyt);
		window.draw(keyy);
		window.draw(keyu);
		window.draw(keyi);
		window.draw(keyo);
		window.draw(keyp);
		window.draw(keya);
		window.draw(keys);
		window.draw(keyd);
		window.draw(keyf);
		window.draw(keyg);
		window.draw(keyh);
		window.draw(keyj);
		window.draw(keyk);
		window.draw(keyl);
		window.draw(keyz);
		window.draw(keyx);
		window.draw(keyc);
		window.draw(keyv);
		window.draw(keyb);
		window.draw(keyn);
		window.draw(keym);

		
		
		
		window.draw(rectangle00);
		window.draw(rectangle01);
		window.draw(rectangle02);
		window.draw(rectangle03);
		window.draw(rectangle04);
		window.draw(rectangle10);
		window.draw(rectangle11);
		window.draw(rectangle12);
		window.draw(rectangle13);
		window.draw(rectangle14);
		window.draw(rectangle20);
		window.draw(rectangle21);
		window.draw(rectangle22);
		window.draw(rectangle23);
		window.draw(rectangle24);
		window.draw(rectangle30);
		window.draw(rectangle31);
		window.draw(rectangle32);
		window.draw(rectangle33);
		window.draw(rectangle34);
		window.draw(rectangle40);
		window.draw(rectangle41);
		window.draw(rectangle42);
		window.draw(rectangle43);
		window.draw(rectangle44);
		window.draw(rectangle51);
		window.draw(rectangle50);
		window.draw(rectangle54);
		window.draw(rectangle53);
		window.draw(rectangle52);
		
		//update the guess list at the bottom in the loop cycle
		input_one.setString(guess[0]);
		window.draw(input_one);
		window.draw(input_two);
		window.draw(input_three);
		window.draw(input_four);
		window.draw(input_five);
		window.draw(past_guess_one_letter_one);
		window.draw(past_guess_one_letter_two);
		window.draw(past_guess_one_letter_three);
		window.draw(past_guess_one_letter_four);
		window.draw(past_guess_one_letter_five);
		window.draw(past_guess_two_letter_one);
		window.draw(past_guess_two_letter_two);
		window.draw(past_guess_two_letter_three);
		window.draw(past_guess_two_letter_four);
		window.draw(past_guess_two_letter_five);
		window.draw(past_guess_three_letter_one);
		window.draw(past_guess_three_letter_two);
		window.draw(past_guess_three_letter_three);
		window.draw(past_guess_three_letter_four);
		window.draw(past_guess_three_letter_five);
		window.draw(past_guess_four_letter_one);
		window.draw(past_guess_four_letter_two);
		window.draw(past_guess_four_letter_three);
		window.draw(past_guess_four_letter_four);
		window.draw(past_guess_four_letter_five);
		window.draw(past_guess_five_letter_one);
		window.draw(past_guess_five_letter_two);
		window.draw(past_guess_five_letter_three);
		window.draw(past_guess_five_letter_four);
		window.draw(past_guess_five_letter_five);
		window.draw(past_guess_six_letter_one);
		window.draw(past_guess_six_letter_two);
		window.draw(past_guess_six_letter_three);
		window.draw(past_guess_six_letter_four);
		window.draw(past_guess_six_letter_five);
			
		//draw the letters
		window.draw(textq);
		window.draw(textw);
		window.draw(texte);
		window.draw(textr);
		window.draw(textt);
		window.draw(texty);
		window.draw(textu);
		window.draw(texti);
		window.draw(texto);
		window.draw(textp);
		window.draw(texta);
		window.draw(texts);
		window.draw(textd);
		window.draw(textf);
		window.draw(textg);
		window.draw(texth);
		window.draw(textj);
		window.draw(textk);
		window.draw(textl);
		window.draw(textz);
		window.draw(textx);
		window.draw(textc);
		window.draw(textv);
		window.draw(textb);
		window.draw(textn);
		window.draw(textm);
			
        //update
        window.display();
    }
    return 0;
}
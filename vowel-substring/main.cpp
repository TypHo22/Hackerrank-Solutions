#include <bits/stdc++.h>


/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

std::unordered_map<char,bool> lookUp = {
  {'a', true }
 ,{'b', false}
 ,{'c', false}
 ,{'d', false}
 ,{'e', true }
 ,{'f', false}
 ,{'f', false}
 ,{'g', false}
 ,{'h', false}
 ,{'i', true }
 ,{'j', false}
 ,{'k', false}
 ,{'l', false}
 ,{'m', false}
 ,{'n', false}
 ,{'o', true }
 ,{'p', false}
 ,{'q', false}
 ,{'r', false}
 ,{'s', false}
 ,{'t', false}
 ,{'u', true }
 ,{'v', false}
 ,{'w', false}
 ,{'x', false}
 ,{'y', false}
 ,{'z', false}
};

std::string findSubstring(std::string s, int k) {

    std::string subS = "Not found!";
    int maxVowel = 0;

    if(s.size() < k)
        return subS;

    const int n = s.size();

    for(size_t a = 0; (a + k) <= n; a++)
    {
        int b = a;
        int vowelCount = 0;
        //std::cout<<"----------"<<std::endl;
        while(b < (a + k))
        {
            char c = s.at(b);
            //std::cout<<c<<std::endl;
            if(lookUp.find(c)->second)
                vowelCount++;

            b++;
        }

        if(vowelCount > maxVowel)
        {
            subS = s.substr(a, k);
            maxVowel = vowelCount;
        }
    }
    //std::cout<<"========"<<std::endl;
    //std::cout<<subS<<std::endl;
    //std::cout<<"========"<<std::endl;

    return subS;
}


void check(std::string sol0, std::string sol1, int i)
{
    if(sol0 != sol1)
        std::cout<<"Error in testcase "<< i <<std::endl;
    else
        std::cout<<"Success in testcase " << i <<std::endl;
}

int main()
{
    check(findSubstring("caberqiitefg",5),"erqii",-1);
    check(findSubstring("azerdii",5),"erdii",0);
    check(findSubstring("qwdftr",2),"Not found!",1);
    check(findSubstring("eiuaooo",4),"eiua",2);
    check(findSubstring("eazuodeasjhevmfcheleeldmgomahlxnhuuuaqfcxgzkdwkwtbmkanlcccvczyaovocymcmxmzqnwmyghfefdlxyhzqhzevckzdhuuilrcemkkwenzgushpuncfpgpfwncnhevwpygekelwiqofrkladrfkmamzrbiswymroojjzxzygfkvydyxmkibnxzddculxabokiqvdfvbkxxgblcthakypmzhtkxtqnvafsgcxatezsqjkrefihwymurodbbwjtwqxwtbqepqtwwtdrtecvhphdcnhqpjakimxbtuymqdnltmhslyklzvhgroeeqrvnsbwkrvpvvbywjlqtecuaonkrpntacwyzxvahcmsorygalsgccnkgokkstjxwxsqwnyuiunelcxbvarodcztuwwukvgnwvvqfgvfcfybworgpiptizoofpimgrrunduykvvfueknonsxztptlbzlrfcocerpjgemrxmsaxyllqhdkynlsnqagewykfokjqwvsswqwqykaattqghtzuwksdnyvmoqokulxkcabbygvzeqahwxrmqkexmgghipmpszmajlamlsywqrcvhpzhxabkuzzhnbjbfiglfflbfcfnjhyrsztscolzlhwdvxqubafbxdkxhkoiabhgvzphurlwrnshkmzcfdhhvrgkuppdclqsnyceamkxkyctbmtwnslzxljbimnotlmhxojvgjacdilitttdveqvgpwnttutkiksnvcuesrblpacmuapltsohnyycqjnxidkrwbndubambieqovrtpyvqrrgokragwuteupxxixycvwvmjxibhhitmdkvqafnzdzpvyydcoroomndmrseslvhkbppcqkmhxlgsjvqucvfqtwjrtheisvboaxtgtrjoamphlhqtsfdaxdyslvebypukeopxuvtkqydamcpdjydrwpfqqxekkmfgdppcqpwiwndjqkxllqplbqxgecsbnvlkeedfqcjpledqymbccmzyvwqbkoamvllqkpnaygmwvkldngysmqrokswpfsetbptcvwzcqrfxnlqftcbfwapawpeerbqclxcbjbwaxvzaxjdawsqevbprcnrwylnrboejvixzrjtkddceliladwymlwzwzsjncatjcakodewxcebkvkrtntalhruzwsdllrqhaojqpywgrkwrwdkngmnaubhrvcmffielfqdcmwpgclpnwzpjinmitgowkzqvcenhgagczutlxecdgrxinsqzvmorphjgyhjlqxtytmphqujpcoaorntyoqgdqflqbrbfxjhtlkgrxjnxgsqhxxqfyuccuyrmafaqbviyykkfwznzmxjioyvkuxynieubcosixsyniikzszztoooaekcbbwyworydpicfuqifgtnvdadjepwvwcnubvkpuzsasvmyannyvhqtpqaafqejhfurziwdnrxpnugibgfktfohdfzygzchdjzlflojderzqwfdufymmbqgeaerzeucwzlytyvjzkqytxkiyxhtjduiqgkcofhiarkhclyfyekommbejjyrwgtserxwwrvlkvajhmvdypoyffwthmjujnxlgfdhiwbktaqmeiuxbtfmjeldjdgbwhfvcvrginuezlrqjwqbuebbyqiuwtlrzurkzqqhovsprhdjxwkktgnswwnvgtmmiqpdgmwqhgdnamhuhoussicoysbxpdsoulndbtpnxurvawdkjpebnrawzmmimloencfssoekdptahthxdqvqaizxbzypcwwtoujereghkkainyegvjakhfoqhiilfyolkvohcrpfsgtrpqtunchvhevvrcjuzsbwdkqynrtqxyueqdxzzcorkuqmdefwzjbtvlxsdblmcgpeqtentgmfbhfkptodurrtguuewokqsgpjqtmrskuuhokcdopccmyqjroygkczpnkljanvrgqygvpezfxovpeepqpuenrxrbfxngefivqmwqzuiruvchlmkfwpzgyzrpxaqkuhcdtisnifqcaumcwlvfmbtisnocqgkcpjhfnedirtxwgmzggbjanvclpvkoivkofrtczndpovcizfbiztugjsjnddxnzkpqjsdmasgjjuwvzhzkznkqeexvxxcpcwnowqitqljymspnzygaznuvbjaqsbnxuxhmkmimzkmpnxacttacpeshzerguwjesjglcivushpsqievtvhcbbqngdytzwdlopojspavyygnsuvzqecmlgmqrqbowzkiielycasljhtgfjdgbrantdeiilygeydfvyxhmetphvalanwmoetvtxmvjqvxvwbhrhxjkujcreeaadpqjlhnuvffivwfbfpgdssgundgimnkltjvykzmdppjbxutrclnwecqvvwrycaffmgjzpyqilfcicbowtxamjoejdmmjnkyujlfgaiddwkssdxcmceipjkbuipwizhbtrqliipwnzuythdfdovecbwjrsqniixgvvhrxjsgwsdsakuekuknflevljwfvvtryorkfqibbbnopwwacjnmoeypothhxtoyrtfvhdnrdhncqsrvjbjedlcltvyvpmmpngsguqrtyjgkdyczhqqnssfjiwhuwhjronaloflbujfoarcrtedixjnldjybekhigjzrngixozwvjonuysbondxjwwinfvbnlfnbklszvhpphsyootizehnubzmpyhowwrdsyzvlrhfcogpyktsvtznggxqimlztabmttmyzchgfutauerkpvxbduokdbtuezeudidwsfvbzmouukvpbolletxjshxrhogyzjsptsuiqtlytxznxuxlcfuklxvzysamfejbghjnjtaficsazylyhfzbxxlqyzzskoddjwemnhijvlhbpqfioaaqjwjzlfjyscnepnojaaxyiwnzfkewlmnvbdapylqqniqouytoweqyguusmgbkkcimbiiuztduiokjlibqvlwquesimiqwaievmptuqpvjizdyrqdrcxzbwmxoegnsekfahzigrjwpxolaokkwylbfygychjpgvdusmfceibiwtortqyaclswyvvoztxxesucalklbphmpxyqnclvjkkhbwspukdhpcghkhnpcjqclqfetqhoxzadfnjyjnwjhozxpmpfaguzskgaszbshgevyqgxieuyzylgznroypkwdzbjekmxpxilvoesnjrnflwxoddynocomylpbqwptmaxuociswamnbhphypakpwgnmouiabfllywlesenhlrdwtkdkoozmavkxayoxwuzzoqtsmvkekhtdohkqlmepgyrwimnaisjipmfvplqwtpbpsbynapwwexwbppdbzlwmxxkwyqqbqpkeqqirvynejkowtpvadkioznxltmymjnizdulwhimthancilqihkqjtirusuikxowaduzjlgwknizylcstnltjbxdamfvdadwhfgevxdbcnsvqfonknjtdlitigrmhlognhiturolpruwgkjmsnfkihvcioblyllmlbolcyxlfvbolblyptikgziuiunahebqejwqkhhfyffggmppbjqgnkxpnjlurmzgwricxsesdvdvercllsyzlkgmmsybrozpthvkhrshhagbohohejwbhtqavizyfmvrbkbfgbutysgkrfigqweroehdsozuzkwvlaljbxbvxuriwbkgvxxamyqoiryxaajvexbfmnridhoovrmtunmogtghagefuoypugedurmfmbmzlloylafrskdicrdnkebjtufdcsbqmktvohaaupskecvkagyizvfhslfeuyvhfwzpgrsdljatqplexqsqvdjtqizzaaanwkjjewnzuieqapqmqmjvuznufzukithigbljxsfhbmatwaimbumomyreogqjmpszpfkujbnaxgecxzfemevsyqckxzmbmgxlmnldislishbnlfpoafwrvlsygkznyjtgiohbzclbhjmfwolwgowregoyzfhlffdoxqbyvpjkhcxulpsdsjkbppraezupwskqvlakybjuunadrwpxknxfiunqrgoplmrwwdptqpvtgielwdkebslrmnyqhawnuidcrbaaeakzezsedcvvssstlmhtmwnvkxvelwhalsgvbgoujjppngyzohzpufyokjrciqrvzxumrfudgkoiixqlcdwdmnvaqqwalgbofamyakekmwvlkjvijiefzlanwrojtdtznasndgksffbaemdxpborzxkmpzragjnsnfaccqyocoaxolrcqpbvxphouaazmqcvyqcodoaiqfwpshfhrctlxiqrxyacndcexjidmwtizaujnsjrzyahhbppcgfcaemtimbflzkbsrmzmeyzyujgabknwhlxwxvvlmbtkbdvrgihdyhdryzkluzkrxzonwdsbgeaobfvcnkjsdjhncqicegswkekqpqyzyhwumynppmbylyumgkmfvfxmrkhqudcqejpkiktocgdagkcygyeasxyvfwtpmhthkaiivexjgfoehpgyifcngschqkhzlyfhylovkrxzedgwtibyjdcephtzmapqwolzadjrqflitvlzokrwjiuoplrcstvrnatrxkxrjissbiwgqjwcjrtzpcvagwnraizozkxgfxgovwslywlsoplbqqezjejuzjhuexqaptunotnsnftaeipvytikerjjisnzxugjxshrkypulkqlvepsoiaqnlivxctsjajirqhvlrhiwastywlyksorsqwcrwooexcnfmkwthckzoyjvvhmebwhljeokjyreggxvfappxkgnzfmzhpysahxefrzdotpkitvjxkbceujqxdovohwgmwwrqtkxlshntnqosllwrikgqotyxyhodzoemgkcyeozfxvjtgdavgfeunilbqgnvchoqpwaybgxkqlatzughmqnysrlwsgpnegedbkrsqnbjurlqusutmerlscuymngpcdgfokuycuxvdlzoyeynawgbaxlgsfptovspqdwmvyqwkbekhkayrolthmfplonfyrnnczjjbrxzqozvkcemtenjspyhuzchzyafslotswmqbgjtlvpomfodorscexhnehtmafexjdlbtsimxobdbuueeiuzryuysjgzshtwzgtclluvlernzqohefzdxgjmajgsutfkigvvsvuxafxwkqthullkmekqnbefgxkxrscsmqdorxjxahjcrsmevnxmoniojrrkkqdmbhhjvyjwuulomgcgblkmliqfrwvuzkvtoroqatnbbvlhtmylwzsazldavyultepmiodtfjdclitocwfjbzngyoqccgvbrwtvjaqpniibrqkgiqusbflcuzhbwwlvgkkkvebvgfscfehlzuvlgztlqrmdzmevygojxkqloadkfawosmmuohmnddkpyyiivdlouarzmfsdsmrtkycqvbkxjbnoksavxiipqsesqmucpbxchnlwgicmcxaixqmbvxurliazclrcxedotnyewuymjcutltafitfaqkkciowludjsvdasjhipzapsovqekmdzcdoxkaidogzdckddampxaqlexxurmahmxvylojndfakngqhkmumfwhzrtziskcovhppdtapdayxyzxatxdkcofgevjpdgzowpmvvxbwhyeuashtszjvvlqapthhdsvahecrbdyddzutoqtfdathexrxobldjkcwootsnqctvthlhvonkruytoxeymlntwtyulwudqocbbgzbnltblwpphywoycnrtztnogznddzcubrfnqjmekforwncuohkfcgzwpmdzzyaeajpthkcdysncwzovuncqkblrjwoxiluqmwlsbcyleiyvbnerulivmmerrdpsgizocjkpgwqoqmlofsakgqvdnnghnzkuyxrauqbmlliakxchaeebygdifouexpmmdsmnndzftfppgnxljfhqimgvdvlydxvfvqzizfycequwvdgpputeaerqpxxdxrpllxveuzurqszgbxmbweimnyhvxuqqbvnkfkgulptqzcchixrxopjnpiqiqkmhmpmjdlwvrfibkhcypnosuffgbcoxzkmhllwuhilgkmopsemkdfotuzyqxwieyltlakhlhmwhmllbdhqnwxtaxqusdnyavnrprpiyjyolqfarwomfvapdgieafbhvkqpnzagpmtcsvhltkyzieeeltbjejtkfttaiapxkmdacnaqiftqvxnpjaapnzusbwrcjnpbiiomoqpcedsvjpkdklrppgsmaewpanqfdamhnlqyytiuoryurippjchtazsnhidwoseldndfjprgfgrzdffliwrowrwhzqdawnlzvwhpdtjulfsllifmeeftxjbmfacjjyjapmzwklcgmdfwdmlhjkquxyjybkeqrslyhavmhntuqhoekkosoigcqaxsvdiqkbqrwloubdvtjhxwgmzrhkyumvtdwuzhxfqivvajcavmawoyzezkwkfkmatjvebvluhtymzzwwbrisxeujfdznhehmcmqaghjllulnufqabafrxgkmigyxibnhzcbvrknhvhobmpfnogiagsfjnwdvqdnbuqniyyfomgpslfzdqyyyemlmohvwgthxzjxtfzefqpwqxouamujhmbrahvtytwbsybhkawmmorkcjznrvmfqfboudpppwoeinpxctygvuyfdmtjqrrmxrncurirlzbfycbexcpqyqltzwsodiqlezzxszwojusrcclzcwovtebjwxaoskndgdrsbrfoykuqmztswutosuksletoxioiyxtcxaugyntynpjjnwukumiwresiapivbstfvpstgelfevhjnsqezlagotceiylfzvdhminrxhhmfcardhebjnxaajdknrismpsxavqsxmrisighyfybjtlwwreaamkeoqwyrnlhsbuzwlylefotkjkrruhkwybvauooydacyufeiimizgnuupiarsylfrfyvvlaqpihcltjgguxauimcsgtsfmgnipgxezeldwudjxygfimfvrbxnxeryqnhukxaciixcnvnwwxmualicsevnsxxebyhpuodvsvpxacrdfsgxgrxmejcsvuarhmldtylmgamakeikglwchrmjciwakfyjoqlfcpqxbbcdkxsrtnpkjdxtqlcverixaohxazlqvghbiihgdspyflhlswjgholgeuvlxcgmvmmwxgtjfwqonminbpxiuglcvpeppxbgymexxbbydsdefztyahddykkfpxshrlivewbnurwqxfvzowrxcyfwzdvelhelmudstelozdixwlcgftuxwhjabrtwzwpqwzaoahbwfwcwslmszwgvzpxjncqllufitfckvevwiypucjwecfiwikfjlzyfapcioutcqeqngbtfjllrsqpdnyrmbrkzpeizoqbfvmbpeuqtjjzohxvyxlsxvsjwjailfvhpcttmtxguaxwdwrszaeytjbdmmjtypaeqdsbrbywtjnnjcxtnmqxgtumjancfvcgvhxktvrbjtgfsdrogotajcvbmjdhoyjqzobburovewiiailrxluyueuzsiioxsmyctcyytlhvmfzeescbrundcpyfkogepkknnidywxedggsfznbeuvokrgibzhpbkprgaadprgskwufbruiephwbjaafmsowyjszchjrhdzulftouzkwtdjgynduxzcenqwibbpknhxjqslfjbolotrgrnfiyxnthfihckvnesbaeyvvddgdivkvgjqooldenbpyavmbrqkkymhaydikslvmeehugmcswyyevfpsukwfdncnrtxrbzdfiidadblnwphnwscaetsywqlgbalejzuahtujbxtzripvegzyvzngphihmhbmykfisyoywhzxwxspfadbjwhzcrjlyycsvqeqmwyvsbfdsoogrfifrqyxwgulzzafvgfxkpdecnlvframonzcegkpsxllkfvsafujcizovsknforcholnczorsoefehigwtzigdwafjwdpyfclbiknqrzkzkardhqkkuqjqxgxcehcnrazxwwwlnptbnxitpepymglmhubrcwcwtzpkemqyrvvtrrvudkbuvldqetvxxutfvqlphchcslxgrbybmxwtptkbckookysuamgqbycjeecsoehgdbhsldafovljmnibjjkzeqlufmsbijynhvptqejqranhozbmbxsvbeuesivvtufhrkmugdtktegwnihhwuwbhyovbakdckhprcviqzziyqwwvpbjsdcpwacxiigompynxfepffwfjulebodkfhahsfxjdqnwzhblomliznpjriuhydipsokkecbaoinsnncesgldeiqqglgdyexuynypzzqmvshgngdxohnakopdwahojtexjcnitiglljvqyougbddbiqfrwlqnsmtavvlluyyjgxygehvzvblghoqytmpfdonpzhzifsntxtlcumyjstmlzofflosmwvzksbwrycjcknvousytfwntxaxkgsgebctockigskqzlahzatdjfnigrgovvsciwmfxozhvsvrgqxmvlkstqnvzbkihpudurvmiulbtushvhrzmuznigzpxlpgbiudfrfphothrqnmvglyzrqklowbgntscycmwolxwkporouzmgsdzukjqcjzqbemlusouftvngqumeikhhsbmmsqhqgvskvihrwauftmqoaouwcfruexrsqvvanqycpenzxrdgpfnhtxfacjezddgiarnstbkxwidukfmgtwxnazkxgdsynpnuwcxecjeelpenzxnunnqssogmrlwfukwckojbvviwvpitspeisbrnhpjzhdwaoydasiebtoozsbpwarkaazclowpmthbnauwytbjxqhleciasymkuixtkvjjqetkjnnubnzeewujghywmmzuehbqrcyswmbumphxtmnxsyxxceztbfhqcvkvavzmyzwspfqtslandxtmbaietxklrifcvactwwutsiblftejcrncsfuxgoypdtkihjumzstqfotabehtwohfpalqprjjzgrnxbnyxlabmnswkolldluxfdhklliysftuvggbnxkujhcqmmfitgstsoyycccocctjjiancdnimjkpinafdopoplfulytdltzmzmnrkcxvkyqchxswbescsubcgyaqmajfrvzipqnmbfigtgkzjvkqztfsrvbwriwuvrqgelgussaoybbdnepduffmhlwloflzovdeieerxfiyxfdpfynbpgtcriaxlmkvcxjqfeqxqxcfjkgnbifseryjlpifailaxdaetzmpfylfwzqjockfmwcjztzunhtziczfbfibudgbzusuhoeyzjosuqvabzjikffqkjhzhcrfqndtsnfnlsdnfsqfixnjxpizsgilxjkfxbbuflyuvnxhssqadpbkqysghitxoqmmpvzbzfgviewepfuwjcgzngzmkbmhbptrtopvimvgayjjdprbihhoqbikuevuwigffzhvvsjuulewxktvgheyssuatmanzcmadzzflvhlklvhxffjvntfamqiphvasrxeqvlhycgiejavvvnlokxsrhugxjjvdknthtvuyeqekurnqqtfqqhzquogenylmxlesualalptmggzhmafaklwentmsnqmgouilcskopsriaevakfhsjtrisfsjmuhrzebkfkfthwwpxlxbfrbsviaygpdmvvxcaxefuklsxvbxpurdrkylqqphoxgvirsotodqmgtyuotpoqdfqqzhhsxbxbdrdsatveigrobahxcpgrmpjlybzhwmkvdffjmzkhnvjkltvqztsdcxbqposzvdihkinjcebfanbqekbixufxpksoxokautijmfmqyplnrzkldzwkgnbbilwlpjhftaqaodnrwdgtvuixoyxgsbbkugwslbapgxrmvxxsaywnqgejtgemuyjdrhvdvpaqxixudrrtobhbkdcrbjjtgyxfhdzsquwcopslunrhdzizqgeznwnoajjjvpayuuaaehvvpitztgshxqnxdwelwijemfzkcokbvhpghvcltunqhxsjdtxiwkvzwtblxbffocuoikbjepchtptbifbwunwwyoevhtrodmheafcvsiqwvzkixleojaqzovdeecxxghcnerjzhqzfvgekcsawxzclewaavbardjvxxzhnijtfbwarroawnccyahlajgumsjadhxlakgoqlyhshdhpsfmrofnnkjrururevbdihgnltciuzixqukmrenphcetcfewqjudjvfdbuosfltwbndcmthfhalxbepwnlgwidluaevoqrkhenleqndjfbaulaytkuehapcjabwswapshdixwaiixlklwuwrnblkhvjzognfjncuykdxejxbqgpgjbvtuwxfnfzylwmjzanqltkaylswtjkjvdkclbqzhlcqtpkckxjdmmfngqxrbwanuzzeupbtqhhamwqdhdgkclvpkybjsorciuokjnlpekjezojbnbzceznuwujhikrbwyzipvarkswqfwyyszjmaumbjphfjddjfrwmcluawykywfmyntwqvxwvjbtvumbixtvbduakuprqaggorquofmhcdrqqsehyevbemllifraqipitglyvwitgcptldgxlzmosqizrqucbkprvygtxfsbdkjaeewdupywhufifofhfqefffrntrpmitydphmfogkwbnuhwqtmtohilateoqqsyojbjqzcoophiivxjzistwihdqpzaaocnprfjywikwtvhaombwsndijdcrdmhcvuciydtafyspclfdgoobjbvrxqxohpszaqvxklzpwhfhkzigtkqpmaxyzeyemeqhsiwcbigxohfgipfsdiysslxryspdbzvupwhlihxmtkzjhgmhbbvoaruwqfmzyezbhugtayqucfclzxfduwxemiwmxvzyvatjptfqzdnqoeeehhlkuzelctcrbssdfkbaldznjznvjlhcuhhbjyljnlluhdytjokkzlkzffvllwxkqmglihnsvexigjfqjwxgtjvkuxejljrhzldjwsexxugnywxrbxzvdtegexrlsemdtiplnnulojivwfvewnhrtqpegafjuonszqlzhqsucgidekyxthsgcjspmpbablohkvhoxkhhvozwkxikaalbyxtpkkpfcehcohggscxiibjwsnhvhishsgygzdrtyozukhskmmiffsxlorauvndalkgwuxqixvekjwrsvstnxcmewlsozqxbtjtyixnupddkboasgpxltvqkpxflvugywiptmtytpqrcyemsygceurthtutoxxnnwurqjdtgjhavgstybjsltfxvwdplktvtydkjcqjkmrqywauwecazfbzpldggmoopzumubjvdjftjrdzdhysbvhknpzghuzmzhbqurmxohpcgfasjqvnljncroismtlilbqxpuvkzrtomhsvbqcouzjmjdharlbvewhpgcjuqioouejoaiezwcbdbaayrclbzisiwillsncywyzrgmhgdqgxvzotmndgqxnghfqsmgomwvutnkpvgowsyongvjohfqvindxgjnjxwvjkzpjislqnndloisuifhinjvlhrxpjohzcpcsdzvkqsalgvwquvwwzxxznmhadcoeoqpaivsqdzmovvutyrrudzlpvqxsmkgitqqpqhpgkdpiqnfdlvoplpsfkgrampisniewyaomveltboxuemrrzvtcwlcldovdrjuoeafsiztqfaijezjppfmvnzokctrnjbfhiwcfulmykzjdaywmtozkmfexnswfxccndwxllccfsbxgwhfyvemjazhwsqudsbmrciifkaidkbaomkhbekfhljfqpqedhawmfvapjejdriownncpadmxncqzmabxzbqeekadgnsujiomdscngtgfzbhudsblqavhaqsdfroykaxidllqocfxejfzlbvbgphycvepukikpnhekhskafdwamkneueklyeyyvrfxnemnlyssrykzmjztocxzzywgobvmwziphbmcsdublogckgmofggnoxlsrbrntrqecztzaxnqskqooqbcyjxkqnmjeencniatsleqqwycsyqhdqbdubnsydygxmnrwayawnpvjwvjhfwhaqrjhiskiktpaequihszmjkpjmeduvwiowjnofteksikvlxouuwicocvndoxenhbyntknzjcrwfgidpdtjirgxgxstttnbvvgkaosqoimpccpcrwdqgcqrdvkockbpaokvfvmimmpbyfxdamzndaquwazjappdbzngyuigqucawkudbrpovlpcohdzpfinnzvdledqarkusaxckdffbcctgjdoxpqzmazkvpjokjmaqmlsbpcnnaxmwtmyxebahcqdtbyukvglaisoladjhvyspqughdmsbrsjtpugcaepofozzkshlxwdtzajpoaekkvuwakkqujbupxdtdjpbebwcksdhhtnugqccqdphvkehwyxxyiuhryrzcoothtbtjjgbznejgvqtfutimzwereyhfyjpczesaqhiqzhhbohchaljjkaccvtaxgxctgpkjzjcuvyqwyzvyimmretklvgevkwtrqkhueqxxrcmhnhndgtpphtmxznisnqgkvnmvbhxsicjaoskszwbgxougofzgjwpockhyjtzxviknmuvhzpokvjoyeobjbdvycbivmcmwbsnplguobthjcsohbgeqppuxrinfbpmuqjucbxhvpnfqqfmuyopufyrrvacuvydkyhpbtfdgphocfcrqatnhphnqrddlyhiyjdybkqvmpnetwbbhlnaulbsfqqhougsecsveomypxaqnsqbgrlnvhwekqwmfgjhpqszensvvxbrrhynchpksaugacxwpykbchxiwuvhpazbkgtlhdrjaeopsotkzeylpkyfeylhukdowpyltffzwknxpwajowhmqtepwphryiifnygdxfpxqazegpjhqgvauivmmtossvxfiyjxnzjtoosqkezlfgrhcytgcrlwwryqhyrmnronmqjoozwavbqswadnmchpmeyahqjqxuueqydbqmpqlykciboqxmjovcxutmcmxtdpmqucwqlfirvtnrmwpdxcgunxfumhtuavlpojlialwysnmefynearchpzlqpjqnyxpfyazkkvsychrssmsmcchjaowanqynxwswnqpkuonrnqosnognctnrobdrdsucahpnffaroqvsisaxtdvpwqesrofdgeepimvniyimyoignhqplfkbcevgqolytbklkmcwvovdkoyhwaghgvfoicbjwmkpybgovdqrhpmciksdwimhzkkqurycreffzvkkszgfkjitqiroedzdhejhktbjhyuufisajxziwxlojyfnhdoynhsqjgcehezmqyxpjktaeebvdunpljlxtvxmtyfhcezgxzbrggkztcvkjthnquixttvrlmjooshpptdmjrparhnaojvtuwuekqqpnltvdolncnizeovasamiwupxifswdhlxjtihqxfxwgghrcurdrfwzppylwvtsarahavagqqbmszorxxulcfxdntuxeaajnqghbfjtnzrnahobvewobxznksqkdaehvgnvjvwgqeardrccvdvouiygpkthrwtusiawmvvzavlepsmmwtbgzrhbputxbigdnyounskgoncwqkclkhsllgjypyamesndmmzsoolcutdcgmirqjljbfqhysvhqvckiohktreswlmlmtqjazbszpstdrwudgocwslaiaaornvkvteiynkzlsoweqbveraexamwzovormclpidahrbzqptrqowjefjvmvkkkdcrbfckxoqmefomqzbspzpppgzpihngoimoawngemzspgpkeqmbkfywtikqdxgrjjpdarndidqkkeuclobcniubhsktokqljafeftbkxtkkknrvpoznqpjzgfixoafffpwwikekzjzaegwlszkqpnuxibbcpzzxeolsefyhhqsaxycmrrucswcdvylafojtcxltjbxfggwlcjftykslzbxcwrpcfnmtmpeaxeatyhllwnmzzflultzaavnsvtmxcybqxeoxqcdiuddwyarwigjzrodjrvjjwoxiowfsfzrjwkigbiipouggpmoavyiovggmityplyqzlohwcyfpcrsojajmnbbuuryllttjujyiroklsrpmnizlafjspbjyypshqcmfcqxvwivfuwevnspwmjllqwvcyrqwupqcyrgotwjqssehtjxzhacocdfkxbedthcptzwjlpkfecklnykgknzvgptyotmblknojczuyepbbarntlvcgdaobsyifzmwfquxrndlcrwgtotxdegklueilmpkfxqkimcfmgjuscjabpzklrrbradquyefqbvysfmgadnmpmcamrnobyjkjgdkpzdncsddnzyprevlzohfmtfqebqwytxqglovkiztgoxtjhjhyxcxzswawppaslqnrgnfflgcjxbmhuxnruwioytpamfspailyeoxnwobvpgouktanadrsdeaowqzknijfopntelhbmvkbjkygmtjxedgkeehwbjqglbzlvzugcfoegfipmtkbaxyxrmohuuywqbtbetydimyrbyzsncmknjranktvsenpzxaalgaxdmgfkdytjecpzlnalwhpgimoivehyexvjsuwlzmtselvznfboyqatugoecwvgktxarcjaakxnfnxzsgzyidcdxljrxqmmjfjnvdqtzoztvenoxssnqunetzjiuoszpfgojuzdhjpagdlnwtbzbxwbwrdszevzkxryfpositumgpidvknnzlmlrornriyeniecrmxhapduwgklxdaovnrgvwfxdsmggptsesyjgtbfxcoadqlmgdzgwzvkrdxgfmlefjcqrlbxdefxabmikxxwrqppjnprqndapetmjayfzvpknkbxhjglzpvfqhrphhnqzcgfihbpgfwjzvksodmprrmrxzyagrxoihhijbgjacxhzrtudfhwsrgfmjcxmduynnqcvmgcrnfufqeozgezxbgxjzsfldozgjftuqbtrjwtgbkipuqxaltshlcochggepqeyjzoxocnmlnpanleabtirncrdrnjnnrqyujbucgopgylnuhbbfcohmacapryvnfrwcsoqkagwcltjobifhshpumnznccfnsfejazixiywvmrdvmjtdclggywgehmobdkwyvuxzebbakbxfobauncbkfrzftcgoerqbqcowanzeqrjjzxolayiaxedssexcnpkcsrctkijrrnkkcvqybcbkoqmyuxwcghvzlpubxfwkfjcmedrxehhifdzlw",621)
          ,"vxuriwbkgvxxamyqoiryxaajvexbfmnridhoovrmtunmogtghagefuoypugedurmfmbmzlloylafrskdicrdnkebjtufdcsbqmktvohaaupskecvkagyizvfhslfeuyvhfwzpgrsdljatqplexqsqvdjtqizzaaanwkjjewnzuieqapqmqmjvuznufzukithigbljxsfhbmatwaimbumomyreogqjmpszpfkujbnaxgecxzfemevsyqckxzmbmgxlmnldislishbnlfpoafwrvlsygkznyjtgiohbzclbhjmfwolwgowregoyzfhlffdoxqbyvpjkhcxulpsdsjkbppraezupwskqvlakybjuunadrwpxknxfiunqrgoplmrwwdptqpvtgielwdkebslrmnyqhawnuidcrbaaeakzezsedcvvssstlmhtmwnvkxvelwhalsgvbgoujjppngyzohzpufyokjrciqrvzxumrfudgkoiixqlcdwdmnvaqqwalgbofamyakekmwvlkjvijiefzlanwrojtdtznasndgksffbaemdxpborzxkmpzragjnsnfaccqyocoaxolrcqpbvxphouaazmqcvyqcodoai",
          5);
    check(findSubstring("aaaabbb",5),"aaaab",11);
    check(findSubstring("aiouapqwrttymnhjkllkkjgkhklljklfjljhlkjkkkkkkkkkkkkkqwrterttyui",8),"aiouapqw",12);
    return 0;
}


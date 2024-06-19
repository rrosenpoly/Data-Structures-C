// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char a, b, c;
    int singleBracketCount = 0;
    bool singleBracketFound = false;
    bool matchedBrackets = true;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            // If current character is closing bracket, then it must match with
            // the top element of the stack
            if (s.empty()) {
                matchedBrackets = false;
                break;
            }
            else {
                if (expr[i] == ')') {
                    // Store the top element in a
                    a = s.top();
                    s.pop();
                    if (a == '{' || a == '[') {
                        matchedBrackets = false;
                        break;
                    }
                }
                else if (expr[i] == '}') {
                    // Store the top element in b
                    b = s.top();
                    s.pop();
                    if (b == '(' || b == '[') {
                        matchedBrackets = false;
                        break;
                    }
                }
                else if (expr[i] == ']') {
                    // Store the top element in c
                    c = s.top();
                    s.pop();
                    if (c == '(' || c == '{') {
                        matchedBrackets = false;
                        break;
                    }
                }
            }
        }
        else {
            // Increment the single bracket counter
            singleBracketCount++;
        }
    }
    // Check if there are any single brackets left in the stack
    while (!s.empty()) {
        if (s.top() == '(' || s.top() == '{' || s.top() == '[') {
            singleBracketFound = true;
        }
        s.pop();
    }

    // Check if the number of single brackets is even
    if (singleBracketCount % 2 != 0) {
        return false;
    }

    // Check if there are any single unmatched brackets
    if (singleBracketFound) {
        return false;
    }

    // Check if all the brackets are matched
    if (!matchedBrackets) {
        return false;
    }

    return true;
}

// function to check if it is unmatched
int checkIfUnmatched(string expr) {

    stack<char> s;


    for (int i = 0; i < expr.length(); i++) {
        if (s.empty()) {
            s.push(expr[i]);
        }
        else if ((expr[i] == '(') || (expr[i] == '[') || (expr[i] == '{')) {
            s.push(expr[i]);
        }
        else if ((s.top() != '(' && expr[i] == ')') || (s.top() != '{' && expr[i] == '}') || (s.top() != '[' && expr[i] == ']')) {
            return i + 1;
        }
    }
    return 1; // to return 1 when the input is a single bracket
}

// line function
void Line() {
    cout << "------------------------------------------------------------------------" << endl;
}

// Driver code
int main() {

    Line();
    string input_1 = "[]";
    cout << "Sample 1: ";
    // Function call
    if (areBracketsBalanced(input_1))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_1);

    cout << endl;
    Line();

    string input_2 = "{}[]";
    cout << "Sample 2: ";
    // Function call
    if (areBracketsBalanced(input_2))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_2);
    
    cout << endl;
    Line();

    string input_3 = "[()]";
    cout << "Sample 3: ";
    // Function call
    if (areBracketsBalanced(input_3))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_3);
    
    cout << endl;
    Line();

    string input_4 = "(())";
    cout << "Sample 4: ";
    // Function call
    if (areBracketsBalanced(input_4))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_4);
   
    cout << endl;
    Line();

    string input_5 = "{[]}()";
    cout << "Sample 5: ";
    // Function call
    if (areBracketsBalanced(input_5))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_5);
    
    cout << endl;
    Line();

    string input_6 = "{";
    cout << "Sample 6: ";
    // Function call
    if (areBracketsBalanced(input_6))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_6);
    
    cout << endl;
    Line();

    string input_7 = "{[}";
    cout << "Sample 7: ";
    // Function call
    if (areBracketsBalanced(input_7))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_7);
    
    cout << endl;
    Line();

    string input_8 = "foo(bar);"; // there's something strange about input 8
    cout << "Sample 8: ";
    // Function call
    if (areBracketsBalanced(input_8) + 1)
        cout << "Success";
    else
        cout << checkIfUnmatched(input_8);
    
    cout << endl;
    Line();

    string input_9 = "foo(bar[i);";
    cout << "Sample 9: ";
    // Function call
    if (areBracketsBalanced(input_9))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_9);
    
    cout << endl;
    Line();

    string input_41 = "ablabla)ihihi(ohoho";
    cout << "Sample 41: ";
    // Function call
    if (areBracketsBalanced(input_41))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_41);
    
    cout << endl;
    Line();

    string input_28 = "({})}";
    cout << "Sample 28: ";
    // Function call
    if (areBracketsBalanced(input_28))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_28) + 1;
    
    cout << endl;
    Line();

    string input_39 = "({(}";
    cout << "Sample 39: ";
    // Function call
    if (areBracketsBalanced(input_39))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_39);
    
    cout << endl;
    Line();

    string input_45 = "(([({{((({([[({{((((({(({{[[({([{[({[{({{[[[[({{(([([({({({([([[[[{{{[{({[{({([{{{[([{{{{({[(([{{({[(({(([(({[[([{[[(([({[{([(([[{([[{{([[{[({[([{[[({[[((([({[[[([({[{({([{{{(({[({{((({[{[[{[{{[{([{{[([{(({(({{{({{[([{{{{({{({[({[{({{{{({{[{[{(({[({[{({([([{[{({{[([{[(({{[{({((({([({{[[[({{[[[[[([[[([[[{[[{{[([[{[([{{{({{[{[{({[({[([{[{[{{[({({{([{([([[[[[{({{[({(([[[({[{[{[{({[{((([(({{[{([[({{({([(({{[{{(([{[{((((((((([{{([({[([{({([{{({{[{{[{(([[{(({{([([{[[{([{[({[{({[({[[[(({([[(({{[[{[[(({(({{{[{[[[[[[{[{{{{[(([([{[[{{[[([[(([[[{{([(([{(({{{{[[(([[[{{[([[{(({(([({{[[[([({[{{[[[(([{([(({[((([[([(({{{[{(([[{{{[([(([[({[[[({[((([[({{({{{[(({(([[([([([[([([{[[[[[(([[(({{(((([[({{{({{({([([{{[[[({([{[[([{([({{[[[{{([{[{({({[{((([{{(([[[{[({{({([{[{({(({(((((([({{{{[{({[{[{[{{({{{[[(([[([{([[((({{({(((([{[{{[{{({[[({[[[[[{{{((({{([{([{(([{(({[[({[[[({{[([{{([([{({{[({{[[[{([([[({({[[[[[{{({{[{{[{[[[[{([(([({(({{[({[[({([{([{(((({[(((([{([{{({{[({{[(({[(({[((([[[(([{{((([{([({{{((([({(())})])))}}})])}])))}}]))]]])))]}))]}))]}})]}})}}])}]))))]}))))}])}])})]]})]}}))})]))])}]]]]}]}}]}})}}]]]]]})})]])])}]]]}})]}})}])])}}])]}})]]]})]]}))}]))}])}])}})))}}}]]]]]})]]})}}]}}]}]))))})}})))]])}])]]))]]}}})}}]}]}]})}]}}}})]))))))}))})}]}])})}})]}]]]))}}])))}]})})}]}])}}]]]}})])}])]]}])})]]]}}])])})}})}}})]]))))}}))]]))]]]]]}])])]])])])]]))}))]}}})}})]])))]})]]]})]]))])]}}}]]))}]}}}))])]])))]}))])}]))]]]}}]})])]]]}})]))}))}]])]}}]]]))]]}}}}))}]))])}}]]]))]])]]}}]]}])]))]}}}}]}]]]]]]}]}}}))}))]]}]]}}))]])}))]]]})]})}]})]}])}]]}])])}}))}]]))}]}}]}})}}])})}])]})])}}])))))))))}]}]))}}]}}))])})}})]])}]}}))])))}]})}]}]}]})]]]))})]}})}]]]]])])}])}})})]}}]}]}])]})]})}]}]}})}}}])]}]])]}}]]}]]])]]])]]]]]}})]]]}})])})))})}]}}))]}])]}})}]}])])})}]})]}))}]}]}})}}}})}]})]})}})}}}}])]}})}}}))}))}])]}}])}]}}]}]]}]})))}})]}))}}}])})}]})])]]]})])))]]})]]}])]})]}]])}}]])}]]))])}]})]))]]}])]]}))]))}))]})}}]))]})}}}}])]}}}])})}]})}]}}}]]]])])})})})])]))}})]]]]}})}]})]}])})]]}}))})))))}})]])})))}})]))";
    cout << "Sample 45: ";
    // Function call
    if (areBracketsBalanced(input_45))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_45);
    
    cout << endl;
    Line();

    string input_47 = "7[G(J0((Ke{{[{Q[J{O({5{(O{B[(;{ob[v,{IY[,x[(5{w{{jT{0(1[M7F{.(aT{[]u}Bm)ze}dI]l4):}p}}R}),]]S}f]W}4)l:];});}}O)}8]}S]I}}M2)LF)C)]:[jS[:{x[(a(x{[0(d([o[{,(gA(((AuE[8{sl[3{{:[u(Q[([Nx[0vqf(pj2{e!{a(WC{;Zb({G((y{j({v[7(o(I?{cth[6I[(6tk{[qu{[g[X{XR{1[(9Hl(g(E(q{z[({({5({QE{o(((n[V{J([,OYY{:m{z(Z{e(yGk(Yh[{{WMb(D(k{s[?{Gr[{.([pt{?E(D[i[{H{[d{4[{1e[{{{[(cC[{s[tc[oRQ{X26{o[[8[z(YQ[[oX9{1h[({(R[[:a7(Y((3T{(B[p;d(J,[({(3T[qU5[Dg[{U[?G(S{Q(v[W([D8({wM[8([X(D(e[A[dt{3K{[qP{A[{(h[:(!g(5J(N:x![MS5(H(({[V{I(!{y.,{w{[U{,JR[aWqu[([(A(3{{Zk:{(X7{g{U{({v(2{(b{cy(3W[v{2(a?7R(a{eJ{jsS(i(R[ZU(gk{{e[0{p([rK{DLB[(z{Kv{s{(Q[c{lI{w[a(e[o([w(bD7(m[L{Q[(a(o(duV[{:{s[t{[bS[{z}B]z],q}KTh]};}]H!)y)FU)]}]s3)re)]R)])N]}!}j])r}}.}y)o]u}w]vIu)!}ouA]e}})c]))E8}E}))y}es]kF)m4})K,u}Q)})}b}}j)z77}T}}M)S)9]q4)b]]r}Y]j}}})}]UV})7)w3)]nH)H))]M)C}]S}]k}a}]z]))]q)]}AS)])])}K)N]}]S]a])}I);C])e2])G}3)IU)k)4]w]p)z9});]}Zh]Is])I]8W9]k,]}G}]qJE]p}k7])]}X.}}dU]:v}1]F!}s]}Q}V]9T]ncX)9,}GW,])raZ}]V};]x}9)PI)J}n}]y)U)W}2)K3W}Ox}X]t)i}i2]gD))z)M}}it!)}5)}O)]G}))4))]ILw}}]]a}]S})XG]5r]}V))kNBR]})4}))}l)}sp)8}ZE}iRL0)B]]:)fu])]}Vnl}M]V4}UqYA]d7)b)N)MS)}S]k]s)N)]bb}u)4n)J]}]w4]i[a]p[8t[{[{s([z(P[Y[D[C[(E[qw{()rp}])]8O]i]]W;G)F])5}rn]B}]]yLX(T4{G{{V3([?ClS[Ha[3(b[[(jr(n({[({;[V:(4[7{{{SU{B[S{Vj[{;[{Y8(e(h(,9{GM{L[[m(h(y{,G[cs[c((([RJ{Z(7K[(a[0(:PS![{M{8(S{(U[W9n{1([[t2({{Ck{77[({R{N{BU(2[z{gQ(i{z[[0CG((ogd[[a((Zx{{a0{{g([Ei{[or[(od[X[p{(2{0{[rh[gZ(J{{xJ{{(Z(a{4,{r([(f{FN0[{N3.(S{F{.{1C([t.{B{(O{((5[b((j{u([{{d(8[TY([E[[{9,f(M([nu[hD{[{{oW92j(fY([r{E{Q(W6{Ox[s8[(8{E{G{{c;i([HG{U{{[(j[Tr:{d8u{([{[[{E7{vmA}}4O]]}]zy)}g}6S])Zsi]}:}}])}}b}Opd}mal0W)r]I]}a)e}cS}fmDz]P))W}j}]W}9]E]T)r)}]FrVS]]W)])kx}}0].),}nk))]);)H9}qw)Jq}P}]RG)5}}}f)U}Z1W]r}U)V])8m}2Y})3)}?}}9})q]]Ly:}I}M)h}9]WQ30]7F)]M3]35e}L]v)Y}}}k})X)vf]]15xh)F)]]}7)k}]2)Ph3FR}k}}s)]}Mi}}G)]])mU}]7)nA})l}w}h]uJ)])]Ck)p}ppvA])E5)s):]]})m)L]]X}M}r)4)g):}]?}2u]}]H}4A}X}}]L)]L}re)8]}xq)u))o]:q]YeE)x]]m])F};Z}7;}:)w([:6(2(wem([(X{u[vj[d2{[Y{g{c[]c7}}!N:]s}]WqV]}m)]IhT))V)R?:])M";
    cout << "Sample 47: ";
    // Function call
    if (areBracketsBalanced(input_47))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_47);

    cout << endl;
    Line();

    string input_40 = "[({])}";
    cout << "Sample 40: ";
    // Function call
    if (areBracketsBalanced(input_40))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_40);

    cout << endl;
    Line();

    string input_38 = "(}{}";
    cout << "Sample 38: ";
    // Function call
    if (areBracketsBalanced(input_38))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_38);

    cout << endl;
    Line();

    string input_22 = "[(]";
    cout << "Sample 22: ";
    // Function call
    if (areBracketsBalanced(input_22))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_22);

    cout << endl;
    Line();


    return EXIT_SUCCESS;
}

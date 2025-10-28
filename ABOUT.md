The [point of rigor](https://emilyriehl.github.io/files/post-rigorous.pdf) is to guide or build intuition. Even though rigor is merely the instrument of demonstration, just as intuition and curiosity are the instruments of invention, there is no denying that it alone can provide us with certainty.

- Thinking computationally?
    - Computation: Economy of operation and notion of complexity.
    - Data structures: Dynamic and composable definition of the state of any process. This is how we build good programs [abstracting out](https://cizeero.bearblog.dev/) complex processes. But how do you build good definitions? Similar to how you build good categories, understanding your morphism requirements.
- Working through problems often require implementing your reasoning. The ability to reason well seems to depend on information (nodes), understanding (representation of these nodes) and extrapolation (guided random search, open-ness, active discovery).
- Look for density and try to play with things from scratch with the right abstractions.

### Takeaways

**Question & Thonk**: To ask good questions is to attune ourselves to the underlying randomness of discovery.

> "While looking at a problem through different lenses ideally you would want to find the natural world for the problem, express it cohomologically and often the cohomology of that world may solve your problem, like a ripe avocado bursts in your hand." (Grothendieck)

Don't just accept everything, fight what's necessary. Ask your own questions, even if they seem stupid. Thonk - use your intuition to wander deliberately in the dark, to cultivate a sensitivity to lucky accidents, to train your gut by following hunches that lead nowhere until suddenly one doesn't. Thonking builds taste.

> "Change the words. Change the viewpoint. Look at it from every possible angle. After you’ve done that, you can try to look at it from several angles at the same time and perhaps you can get an insight into the real basic issues of the problem, so that you can correlate the important factors and come out with the solution. It’s difficult really to do this, but it is important that you do. If you don’t, it is very easy to get into ruts of mental thinking. You start with a problem here and you go around a circle here and if you could only get over to this point, perhaps you would see your way clear; but you can’t break loose from certain mental blocks which are holding you in certain ways of looking at a problem. That is the reason why very frequently someone who is quite green to a problem will sometimes come in and look at it and find the solution like that, while you have been laboring for months over it. You’ve got set into some ruts here of mental thinking and someone else comes in and sees it from a fresh viewpoint." (Claude Shannon)

When solving a problem it is vital to keep seeing and attacking it differently. Try examples. Try to solve for special cases. Speculative progress can be huge. In fact people should write about their speculations and failures while writing a paper. For if we don't get to know what made someone come up with a construction, then where's the fucking point at all?


**Write & Experiment**: Arguably the most important and recurring step towards solving any problem. This is something I learned while doing functional programming. Good descriptions should be:

- Simple and coherent enough to understand
- Rigorous enough to experiment with
- Succinct enough to use as a primitive module
- Interesting enough to actually give a shit

$$\text{Proof} = \text{Program} = \text{Diagram}$$

**Abstract**: Create good abstractions such that you're able to compress the problem space enough to fit it in your head. Naming your concepts help. Modularizing your problem also helps in reducing chaos. Know which abstractions to fight and which to accept.

> "Ab initio cum recta abstractio."

You can start off by dividing your problem in layers of chunks and while solving or implementing for each, consider everything else as a blackbox. You can further hope to simplify each chunk (or set of chunks) by reducing it to another problem or wishing off several constraints and trying your hand at that. Just as you would construct a proof by stringing lemmas together.

> "The purpose of abstraction is not to be vague, but to create a new semantic level in which one can be absolutely precise." (Edsger Dijkstra)

Another way to reduce chaos is to abstract out the problem and deal with fundamental assumptions.

> "Suppose that you are given a problem to solve, I don’t care what kind of a problem - a machine to design, or a physical theory to develop, or a mathematical theorem to prove, or something of that kind - probably a very powerful approach to this is to attempt to eliminate everything from the problem except the essentials; that is, cut it down to size. Almost every problem that you come across is befuddled with all kinds of extraneous data of one sort or another; and if you can bring this problem down into the main issues, you can see more clearly what you’re trying to do and perhaps find a solution. Now, in so doing, you may have stripped away the problem that you’re after. You may have simplified it to a point that it doesn’t even resemble the problem that you started with; but very often if you can solve this simple problem, you can add refinements to the solution of this until you get back to the solution of the one you started with." (Claude Shannon)

### References

1. [The Two Cultures of Mathematics](https://www.dpmms.cam.ac.uk/~wtg10/2cultures.pdf) by Gowers
2. [On Proof and Progress in Mathematics](https://arxiv.org/pdf/math/9404236.pdf) by Thurston
3. Poincaré on [Intuition in Mathematics](https://mathshistory.st-andrews.ac.uk/Extras/Poincare_Intuition/)
4. [Algorithmic Thinking and Mathematical Thinking](https://sci-hub.do/https://doi.org/10.1080/00029890.1985.11971572) by Knuth
5. [There’s more to mathematics than rigor and proofs](https://terrytao.wordpress.com/career-advice/theres-more-to-mathematics-than-rigour-and-proofs/) by Tao
6. [Ask yourself dumb questions](https://terrytao.wordpress.com/career-advice/ask-yourself-dumb-questions-and-answer-them/) by Tao
7. [Solving mathematical problems](https://terrytao.wordpress.com/career-advice/solving-mathematical-problems/) by Tao
8. [How to write a great research paper](https://www.youtube.com/watch?v=WP-FkUaOcOM)
9. [Seekers and Craftspeople](https://www.amazon.com/gp/product/0618551050) by Lee Smolin
10. [Birds and Frogs](https://www.ams.org/notices/200902/rtx090200212p.pdf) by Freeman Dyson
11. Some [blog](https://codeforces.com/blog/entry/126875) on codeforces
12. Thirty years of proof: [an interview](https://www.youtube.com/watch?v=nlUimyJpWtI) with Andrew Wiles
13. [Capacity to concentrate](https://www.fermentmagazine.org/rands/promenade2.html) by Grothendieck
14. [Curiosity](https://www.youtube.com/watch?v=lr8sVailoLw) by Feynman

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int jAns = ans.nextInt();
        int pAns = ouf.nextInt();
        if (jAns != pAns) {
            return outcome(WA, String.format("Expected %d, found %d", jAns, pAns));
        }
        return outcome(OK, String.format("%d", jAns));
    }
}

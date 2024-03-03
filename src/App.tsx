<<<<<<< HEAD
import React, { useState } from "react";
import "./App.css";
import { Button, Container, Row, Col } from "react-bootstrap";
import axios from "axios";

function App(): JSX.Element {
    const [responseText, setResponseText] = useState<string>("");

    const handleClick = () => {
        axios.get("http://localhost:3000/homepage")
            .then(response => {
                const { message } = response.data;
                setResponseText(message);
            })
            .catch(error => {
                console.error("Error:", error);
            });
    };

    return (
        <div className="App">
            <h1>this is header text</h1>
            <header className="App-header">
                UD CISC275 with React Hooks and TypeScript
            </header>
            <p>
                Edit <code>src/App.tsx</code> and save. This page will
                automatically reload. Also im Alex Hoy, Hello World.
            </p>
            <Container>
                <Row>
                    <Col>
                        <div
                            style={{
                                height: "40px",
                                width: "30px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                    <Col>
                        Why this bird is angry:
                        <ol>
                            <li>Eggs got taken</li>
                            <li>He is red</li>
                            <li>He is frowning</li>
                        </ol>
                        <div
                            style={{
                                height: "30px",
                                width: "40px",
                                backgroundColor: "red"
                            }}
                        ></div>
                    </Col>
                </Row>
            </Container>
            <Button onClick={handleClick}>
                Get Message from C++ Backend
            </Button>
            <p> {responseText && (
                <div>Message: {responseText}</div>
            )}</p>
        </div>
    );
}

export default App;
=======
import React, { useState } from "react";
import "./App.css";
import { Button, Col, Container, Row } from "react-bootstrap";
function App(): JSX.Element {
    const [widgets, setWidgets] = useState<string[]>([]);
    const [widgets2, setWidgets2] = useState<string[]>([]);
    const [widgets3, setWidgets3] = useState<string[]>([]);

    function handleOnDrag(e: React.DragEvent, widgetType: string){
        e.dataTransfer.setData("widgetType", widgetType);
    }

    function handleOnDrop(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
        setWidgets([...widgets, widgetType]);
    }

    function handleDragOver(e: React.DragEvent){
        e.preventDefault();
    }

    function removeAllWidgets() {
        setWidgets([]);
    }

    function removeAllWidgets2() {
        setWidgets2([]);
    }

    function handleOnDrop2(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
            setWidgets2([...widgets2, widgetType]);
    }


    return (
        <div className="App">
            <h1>Gender Inclusive Language Examples</h1>
            <header className="App-header">
                Interactive Examples to enhance language for diversity:
            </header>
            <p>
                Placeholder Paragraph
            </p>
            <div className="widgets">
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget A")}
                >
                    Widget A
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget B")}
                >
                    Widget B
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget C")}
                >
                    Widget C
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets.map((widget, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets}>
                        Remove All Widgets
                    </Button>
                </div>
            </div>
            

            
            <div className="widgets2">
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget D")}
                >
                    Widget D
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget E")}
                >
                    Widget E
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget F")}
                >
                    Widget F
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop2} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets2.map((widget2, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget2}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets2}>
                        Remove All Widgets
                    </Button>
                </div>
            </div>
            
            <Button onClick={() => console.log("Hello World!")}>
                Log Hello World
            </Button>
        </div>
    );
}
export default App;
>>>>>>> 8ad5ba1fe6ecaf7bae121ee2226693f3095ddc75
